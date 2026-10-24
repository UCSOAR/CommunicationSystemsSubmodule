import sys
import unittest
from pathlib import Path


GENERATED_PYTHON = Path(__file__).with_name("_Python")
sys.path.insert(0, str(GENERATED_PYTHON))

import CommandMessage_pb2 as command_proto
import ControlMessage_pb2 as control_proto
import CoreProto_pb2 as core_proto
import TelemetryMessage_pb2 as telemetry_proto
from google.protobuf.message import DecodeError


class FcbProtocolContractTest(unittest.TestCase):
    def test_command_contract_and_round_trip(self):
        self.assertEqual(4, core_proto.NODE_FCB)
        self.assertEqual(3, core_proto.NODE_FSB)
        self.assertEqual(4, command_proto.CommandMessage.FCB_COMMAND_FIELD_NUMBER)
        self.assertEqual(36, command_proto.FcbCommand.RSC_ERASE_FLASH)
        self.assertEqual(37, command_proto.FcbCommand.RSC_NONE)

        command = command_proto.CommandMessage(
            source=core_proto.NODE_FSB,
            target=core_proto.NODE_FCB,
            source_sequence_num=42,
            fcb_command=command_proto.FcbCommand(
                command_enum=command_proto.FcbCommand.RSC_ERASE_FLASH
            ),
        )

        payload = command.SerializeToString()
        self.assertEqual(bytes.fromhex("08 03 10 04 18 2a 22 02 08 24"), payload)
        self.assertEqual(command, command_proto.CommandMessage.FromString(payload))

    def test_control_contract_and_round_trip(self):
        self.assertEqual(4, control_proto.ControlMessage.SOURCE_SEQUENCE_NUM_FIELD_NUMBER)
        self.assertEqual(8, control_proto.ControlMessage.HB_FIELD_NUMBER)

        control = control_proto.ControlMessage(
            source=core_proto.NODE_FSB,
            target=core_proto.NODE_FCB,
            source_sequence_num=7,
            hb=control_proto.Heartbeat(hb_response_sequence_num=8),
        )

        payload = control.SerializeToString()
        self.assertEqual(bytes.fromhex("08 03 10 04 20 07 42 02 08 08"), payload)
        self.assertEqual(control, control_proto.ControlMessage.FromString(payload))

    def test_fcb_system_state_preserves_optional_rocket_state(self):
        control = control_proto.ControlMessage(
            source=core_proto.NODE_FCB,
            target=core_proto.NODE_FSB,
            sys_state=control_proto.SystemState(
                sys_state=control_proto.SystemState.SYS_NORMAL_OPERATION,
                rocket_state=core_proto.RS_ARM,
            ),
        )

        decoded = control_proto.ControlMessage.FromString(control.SerializeToString())
        self.assertTrue(decoded.sys_state.HasField("rocket_state"))
        self.assertEqual(core_proto.RS_ARM, decoded.sys_state.rocket_state)

    def test_fcb_telemetry_contract_and_round_trip(self):
        expected_fields = {
            "fcbPressure": 8,
            "fcbtemperature": 9,
            "fcbControlStatus": 10,
        }
        actual_fields = {
            field.name: field.number
            for field in telemetry_proto.TelemetryMessage.DESCRIPTOR.fields
        }
        for field_name, field_number in expected_fields.items():
            self.assertEqual(field_number, actual_fields[field_name])

        messages = (
            telemetry_proto.TelemetryMessage(
                source=core_proto.NODE_FCB,
                target=core_proto.NODE_FSB,
                fcbPressure=telemetry_proto.FcbPressure(upper_pv_pressure=321),
            ),
            telemetry_proto.TelemetryMessage(
                source=core_proto.NODE_FCB,
                target=core_proto.NODE_FSB,
                fcbtemperature=telemetry_proto.FcbTemperature(
                    upper_pv_tc=10,
                    vent_solenoid_tc=20,
                    dip_tube_tc=30,
                ),
            ),
            telemetry_proto.TelemetryMessage(
                source=core_proto.NODE_FCB,
                target=core_proto.NODE_FSB,
                fcbControlStatus=telemetry_proto.FcbControlStatus(vent_open=True),
            ),
        )

        self.assertEqual(
            bytes.fromhex("08 04 10 03 42 03 08 c1 02"),
            messages[0].SerializeToString(),
        )
        for telemetry in messages:
            with self.subTest(message=telemetry.WhichOneof("message")):
                payload = telemetry.SerializeToString()
                self.assertEqual(
                    telemetry,
                    telemetry_proto.TelemetryMessage.FromString(payload),
                )
                self.assertLess(len(payload), 256)

    def test_truncated_fcb_payload_is_rejected(self):
        truncated = bytes.fromhex("08 03 10 04 18 2a 22 02 08")

        with self.assertRaises(DecodeError):
            command_proto.CommandMessage.FromString(truncated)


if __name__ == "__main__":
    unittest.main()
