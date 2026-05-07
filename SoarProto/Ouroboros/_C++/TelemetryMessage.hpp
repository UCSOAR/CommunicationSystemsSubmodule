/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: TelemetryMessage.proto
 */

// This file is generated. Please do not edit!
#ifndef TELEMETRYMESSAGE_H
#define TELEMETRYMESSAGE_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions
#include "CoreProto.h"

namespace Proto {

class AltitudeType final: public ::EmbeddedProto::MessageInterface
{
  public:
    AltitudeType() = default;
    AltitudeType(const AltitudeType& rhs )
    {
      set_altitude(rhs.get_altitude());
      set_unit(rhs.get_unit());
    }

    AltitudeType(const AltitudeType&& rhs ) noexcept
    {
      set_altitude(rhs.get_altitude());
      set_unit(rhs.get_unit());
    }

    ~AltitudeType() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ALTITUDE = 1,
      UNIT = 2
    };

    AltitudeType& operator=(const AltitudeType& rhs)
    {
      set_altitude(rhs.get_altitude());
      set_unit(rhs.get_unit());
      return *this;
    }

    AltitudeType& operator=(const AltitudeType&& rhs) noexcept
    {
      set_altitude(rhs.get_altitude());
      set_unit(rhs.get_unit());
      return *this;
    }

    static constexpr char const* ALTITUDE_NAME = "altitude";
    inline void clear_altitude() { altitude_.clear(); }
    inline void set_altitude(const int32_t& value) { altitude_ = value; }
    inline void set_altitude(const int32_t&& value) { altitude_ = value; }
    inline int32_t& mutable_altitude() { return altitude_.get(); }
    inline const int32_t& get_altitude() const { return altitude_.get(); }
    inline int32_t altitude() const { return altitude_.get(); }

    static constexpr char const* UNIT_NAME = "unit";
    inline void clear_unit() { unit_.clear(); }
    inline void set_unit(const int32_t& value) { unit_ = value; }
    inline void set_unit(const int32_t&& value) { unit_ = value; }
    inline int32_t& mutable_unit() { return unit_.get(); }
    inline const int32_t& get_unit() const { return unit_.get(); }
    inline int32_t unit() const { return unit_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != altitude_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = altitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ALTITUDE), buffer, false);
      }

      if((0 != unit_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = unit_.serialize_with_id(static_cast<uint32_t>(FieldNumber::UNIT), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ALTITUDE:
            return_value = altitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::UNIT:
            return_value = unit_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_altitude();
      clear_unit();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ALTITUDE:
          name = ALTITUDE_NAME;
          break;
        case FieldNumber::UNIT:
          name = UNIT_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = altitude_.to_string(left_chars, indent_level + 2, ALTITUDE_NAME, true);
      left_chars = unit_.to_string(left_chars, indent_level + 2, UNIT_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 altitude_ = 0;
      EmbeddedProto::int32 unit_ = 0;

};

class Baro final: public ::EmbeddedProto::MessageInterface
{
  public:
    Baro() = default;
    Baro(const Baro& rhs )
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
    }

    Baro(const Baro&& rhs ) noexcept
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
    }

    ~Baro() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      BARO_PRESSURE = 1,
      BARO_TEMPERATURE = 2
    };

    Baro& operator=(const Baro& rhs)
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      return *this;
    }

    Baro& operator=(const Baro&& rhs) noexcept
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      return *this;
    }

    static constexpr char const* BARO_PRESSURE_NAME = "baro_pressure";
    inline void clear_baro_pressure() { baro_pressure_.clear(); }
    inline void set_baro_pressure(const int32_t& value) { baro_pressure_ = value; }
    inline void set_baro_pressure(const int32_t&& value) { baro_pressure_ = value; }
    inline int32_t& mutable_baro_pressure() { return baro_pressure_.get(); }
    inline const int32_t& get_baro_pressure() const { return baro_pressure_.get(); }
    inline int32_t baro_pressure() const { return baro_pressure_.get(); }

    static constexpr char const* BARO_TEMPERATURE_NAME = "baro_temperature";
    inline void clear_baro_temperature() { baro_temperature_.clear(); }
    inline void set_baro_temperature(const int32_t& value) { baro_temperature_ = value; }
    inline void set_baro_temperature(const int32_t&& value) { baro_temperature_ = value; }
    inline int32_t& mutable_baro_temperature() { return baro_temperature_.get(); }
    inline const int32_t& get_baro_temperature() const { return baro_temperature_.get(); }
    inline int32_t baro_temperature() const { return baro_temperature_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != baro_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = baro_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BARO_PRESSURE), buffer, false);
      }

      if((0 != baro_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = baro_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BARO_TEMPERATURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::BARO_PRESSURE:
            return_value = baro_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::BARO_TEMPERATURE:
            return_value = baro_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_baro_pressure();
      clear_baro_temperature();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::BARO_PRESSURE:
          name = BARO_PRESSURE_NAME;
          break;
        case FieldNumber::BARO_TEMPERATURE:
          name = BARO_TEMPERATURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = baro_pressure_.to_string(left_chars, indent_level + 2, BARO_PRESSURE_NAME, true);
      left_chars = baro_temperature_.to_string(left_chars, indent_level + 2, BARO_TEMPERATURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 baro_pressure_ = 0;
      EmbeddedProto::int32 baro_temperature_ = 0;

};

class Battery final: public ::EmbeddedProto::MessageInterface
{
  public:
    Battery() = default;
    Battery(const Battery& rhs )
    {
      set_power_source(rhs.get_power_source());
      set_voltage(rhs.get_voltage());
    }

    Battery(const Battery&& rhs ) noexcept
    {
      set_power_source(rhs.get_power_source());
      set_voltage(rhs.get_voltage());
    }

    ~Battery() override = default;

    enum class PowerSource : uint32_t
    {
      INVALID = 0,
      GROUND = 1,
      ROCKET = 2
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      POWER_SOURCE = 1,
      VOLTAGE = 2
    };

    Battery& operator=(const Battery& rhs)
    {
      set_power_source(rhs.get_power_source());
      set_voltage(rhs.get_voltage());
      return *this;
    }

    Battery& operator=(const Battery&& rhs) noexcept
    {
      set_power_source(rhs.get_power_source());
      set_voltage(rhs.get_voltage());
      return *this;
    }

    static constexpr char const* POWER_SOURCE_NAME = "power_source";
    inline void clear_power_source() { power_source_.clear(); }
    inline void set_power_source(const PowerSource& value) { power_source_ = value; }
    inline void set_power_source(const PowerSource&& value) { power_source_ = value; }
    inline const PowerSource& get_power_source() const { return power_source_.get(); }
    inline PowerSource power_source() const { return power_source_.get(); }

    static constexpr char const* VOLTAGE_NAME = "voltage";
    inline void clear_voltage() { voltage_.clear(); }
    inline void set_voltage(const int32_t& value) { voltage_ = value; }
    inline void set_voltage(const int32_t&& value) { voltage_ = value; }
    inline int32_t& mutable_voltage() { return voltage_.get(); }
    inline const int32_t& get_voltage() const { return voltage_.get(); }
    inline int32_t voltage() const { return voltage_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<PowerSource>(0) != power_source_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = power_source_.serialize_with_id(static_cast<uint32_t>(FieldNumber::POWER_SOURCE), buffer, false);
      }

      if((0 != voltage_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = voltage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::VOLTAGE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::POWER_SOURCE:
            return_value = power_source_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::VOLTAGE:
            return_value = voltage_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_power_source();
      clear_voltage();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::POWER_SOURCE:
          name = POWER_SOURCE_NAME;
          break;
        case FieldNumber::VOLTAGE:
          name = VOLTAGE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = power_source_.to_string(left_chars, indent_level + 2, POWER_SOURCE_NAME, true);
      left_chars = voltage_.to_string(left_chars, indent_level + 2, VOLTAGE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<PowerSource> power_source_ = static_cast<PowerSource>(0);
      EmbeddedProto::int32 voltage_ = 0;

};

class CombustionControlStatus final: public ::EmbeddedProto::MessageInterface
{
  public:
    CombustionControlStatus() = default;
    CombustionControlStatus(const CombustionControlStatus& rhs )
    {
      set_vent_open(rhs.get_vent_open());
      set_drain_open(rhs.get_drain_open());
      set_mev_open(rhs.get_mev_open());
    }

    CombustionControlStatus(const CombustionControlStatus&& rhs ) noexcept
    {
      set_vent_open(rhs.get_vent_open());
      set_drain_open(rhs.get_drain_open());
      set_mev_open(rhs.get_mev_open());
    }

    ~CombustionControlStatus() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      VENT_OPEN = 1,
      DRAIN_OPEN = 2,
      MEV_OPEN = 3
    };

    CombustionControlStatus& operator=(const CombustionControlStatus& rhs)
    {
      set_vent_open(rhs.get_vent_open());
      set_drain_open(rhs.get_drain_open());
      set_mev_open(rhs.get_mev_open());
      return *this;
    }

    CombustionControlStatus& operator=(const CombustionControlStatus&& rhs) noexcept
    {
      set_vent_open(rhs.get_vent_open());
      set_drain_open(rhs.get_drain_open());
      set_mev_open(rhs.get_mev_open());
      return *this;
    }

    static constexpr char const* VENT_OPEN_NAME = "vent_open";
    inline void clear_vent_open() { vent_open_.clear(); }
    inline void set_vent_open(const bool& value) { vent_open_ = value; }
    inline void set_vent_open(const bool&& value) { vent_open_ = value; }
    inline bool& mutable_vent_open() { return vent_open_.get(); }
    inline const bool& get_vent_open() const { return vent_open_.get(); }
    inline bool vent_open() const { return vent_open_.get(); }

    static constexpr char const* DRAIN_OPEN_NAME = "drain_open";
    inline void clear_drain_open() { drain_open_.clear(); }
    inline void set_drain_open(const bool& value) { drain_open_ = value; }
    inline void set_drain_open(const bool&& value) { drain_open_ = value; }
    inline bool& mutable_drain_open() { return drain_open_.get(); }
    inline const bool& get_drain_open() const { return drain_open_.get(); }
    inline bool drain_open() const { return drain_open_.get(); }

    static constexpr char const* MEV_OPEN_NAME = "mev_open";
    inline void clear_mev_open() { mev_open_.clear(); }
    inline void set_mev_open(const bool& value) { mev_open_ = value; }
    inline void set_mev_open(const bool&& value) { mev_open_ = value; }
    inline bool& mutable_mev_open() { return mev_open_.get(); }
    inline const bool& get_mev_open() const { return mev_open_.get(); }
    inline bool mev_open() const { return mev_open_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((false != vent_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = vent_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::VENT_OPEN), buffer, false);
      }

      if((false != drain_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = drain_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DRAIN_OPEN), buffer, false);
      }

      if((false != mev_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = mev_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MEV_OPEN), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::VENT_OPEN:
            return_value = vent_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::DRAIN_OPEN:
            return_value = drain_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MEV_OPEN:
            return_value = mev_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_vent_open();
      clear_drain_open();
      clear_mev_open();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::VENT_OPEN:
          name = VENT_OPEN_NAME;
          break;
        case FieldNumber::DRAIN_OPEN:
          name = DRAIN_OPEN_NAME;
          break;
        case FieldNumber::MEV_OPEN:
          name = MEV_OPEN_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = vent_open_.to_string(left_chars, indent_level + 2, VENT_OPEN_NAME, true);
      left_chars = drain_open_.to_string(left_chars, indent_level + 2, DRAIN_OPEN_NAME, false);
      left_chars = mev_open_.to_string(left_chars, indent_level + 2, MEV_OPEN_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::boolean vent_open_ = false;
      EmbeddedProto::boolean drain_open_ = false;
      EmbeddedProto::boolean mev_open_ = false;

};

class CoordinateType final: public ::EmbeddedProto::MessageInterface
{
  public:
    CoordinateType() = default;
    CoordinateType(const CoordinateType& rhs )
    {
      set_degrees(rhs.get_degrees());
      set_minutes(rhs.get_minutes());
    }

    CoordinateType(const CoordinateType&& rhs ) noexcept
    {
      set_degrees(rhs.get_degrees());
      set_minutes(rhs.get_minutes());
    }

    ~CoordinateType() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DEGREES = 1,
      MINUTES = 2
    };

    CoordinateType& operator=(const CoordinateType& rhs)
    {
      set_degrees(rhs.get_degrees());
      set_minutes(rhs.get_minutes());
      return *this;
    }

    CoordinateType& operator=(const CoordinateType&& rhs) noexcept
    {
      set_degrees(rhs.get_degrees());
      set_minutes(rhs.get_minutes());
      return *this;
    }

    static constexpr char const* DEGREES_NAME = "degrees";
    inline void clear_degrees() { degrees_.clear(); }
    inline void set_degrees(const int32_t& value) { degrees_ = value; }
    inline void set_degrees(const int32_t&& value) { degrees_ = value; }
    inline int32_t& mutable_degrees() { return degrees_.get(); }
    inline const int32_t& get_degrees() const { return degrees_.get(); }
    inline int32_t degrees() const { return degrees_.get(); }

    static constexpr char const* MINUTES_NAME = "minutes";
    inline void clear_minutes() { minutes_.clear(); }
    inline void set_minutes(const int32_t& value) { minutes_ = value; }
    inline void set_minutes(const int32_t&& value) { minutes_ = value; }
    inline int32_t& mutable_minutes() { return minutes_.get(); }
    inline const int32_t& get_minutes() const { return minutes_.get(); }
    inline int32_t minutes() const { return minutes_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != degrees_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = degrees_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DEGREES), buffer, false);
      }

      if((0 != minutes_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = minutes_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MINUTES), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::DEGREES:
            return_value = degrees_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MINUTES:
            return_value = minutes_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_degrees();
      clear_minutes();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DEGREES:
          name = DEGREES_NAME;
          break;
        case FieldNumber::MINUTES:
          name = MINUTES_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = degrees_.to_string(left_chars, indent_level + 2, DEGREES_NAME, true);
      left_chars = minutes_.to_string(left_chars, indent_level + 2, MINUTES_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 degrees_ = 0;
      EmbeddedProto::int32 minutes_ = 0;

};

class DmbPressure final: public ::EmbeddedProto::MessageInterface
{
  public:
    DmbPressure() = default;
    DmbPressure(const DmbPressure& rhs )
    {
      set_upper_pv_pressure(rhs.get_upper_pv_pressure());
    }

    DmbPressure(const DmbPressure&& rhs ) noexcept
    {
      set_upper_pv_pressure(rhs.get_upper_pv_pressure());
    }

    ~DmbPressure() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      UPPER_PV_PRESSURE = 1
    };

    DmbPressure& operator=(const DmbPressure& rhs)
    {
      set_upper_pv_pressure(rhs.get_upper_pv_pressure());
      return *this;
    }

    DmbPressure& operator=(const DmbPressure&& rhs) noexcept
    {
      set_upper_pv_pressure(rhs.get_upper_pv_pressure());
      return *this;
    }

    static constexpr char const* UPPER_PV_PRESSURE_NAME = "upper_pv_pressure";
    inline void clear_upper_pv_pressure() { upper_pv_pressure_.clear(); }
    inline void set_upper_pv_pressure(const int32_t& value) { upper_pv_pressure_ = value; }
    inline void set_upper_pv_pressure(const int32_t&& value) { upper_pv_pressure_ = value; }
    inline int32_t& mutable_upper_pv_pressure() { return upper_pv_pressure_.get(); }
    inline const int32_t& get_upper_pv_pressure() const { return upper_pv_pressure_.get(); }
    inline int32_t upper_pv_pressure() const { return upper_pv_pressure_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != upper_pv_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = upper_pv_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::UPPER_PV_PRESSURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::UPPER_PV_PRESSURE:
            return_value = upper_pv_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_upper_pv_pressure();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::UPPER_PV_PRESSURE:
          name = UPPER_PV_PRESSURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = upper_pv_pressure_.to_string(left_chars, indent_level + 2, UPPER_PV_PRESSURE_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 upper_pv_pressure_ = 0;

};

class Flash final: public ::EmbeddedProto::MessageInterface
{
  public:
    Flash() = default;
    Flash(const Flash& rhs )
    {
      set_sector_address(rhs.get_sector_address());
      set_logging_rate(rhs.get_logging_rate());
    }

    Flash(const Flash&& rhs ) noexcept
    {
      set_sector_address(rhs.get_sector_address());
      set_logging_rate(rhs.get_logging_rate());
    }

    ~Flash() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SECTOR_ADDRESS = 1,
      LOGGING_RATE = 2
    };

    Flash& operator=(const Flash& rhs)
    {
      set_sector_address(rhs.get_sector_address());
      set_logging_rate(rhs.get_logging_rate());
      return *this;
    }

    Flash& operator=(const Flash&& rhs) noexcept
    {
      set_sector_address(rhs.get_sector_address());
      set_logging_rate(rhs.get_logging_rate());
      return *this;
    }

    static constexpr char const* SECTOR_ADDRESS_NAME = "sector_address";
    inline void clear_sector_address() { sector_address_.clear(); }
    inline void set_sector_address(const uint32_t& value) { sector_address_ = value; }
    inline void set_sector_address(const uint32_t&& value) { sector_address_ = value; }
    inline uint32_t& mutable_sector_address() { return sector_address_.get(); }
    inline const uint32_t& get_sector_address() const { return sector_address_.get(); }
    inline uint32_t sector_address() const { return sector_address_.get(); }

    static constexpr char const* LOGGING_RATE_NAME = "logging_rate";
    inline void clear_logging_rate() { logging_rate_.clear(); }
    inline void set_logging_rate(const uint32_t& value) { logging_rate_ = value; }
    inline void set_logging_rate(const uint32_t&& value) { logging_rate_ = value; }
    inline uint32_t& mutable_logging_rate() { return logging_rate_.get(); }
    inline const uint32_t& get_logging_rate() const { return logging_rate_.get(); }
    inline uint32_t logging_rate() const { return logging_rate_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != sector_address_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sector_address_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECTOR_ADDRESS), buffer, false);
      }

      if((0U != logging_rate_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = logging_rate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGING_RATE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::SECTOR_ADDRESS:
            return_value = sector_address_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGING_RATE:
            return_value = logging_rate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_sector_address();
      clear_logging_rate();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SECTOR_ADDRESS:
          name = SECTOR_ADDRESS_NAME;
          break;
        case FieldNumber::LOGGING_RATE:
          name = LOGGING_RATE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = sector_address_.to_string(left_chars, indent_level + 2, SECTOR_ADDRESS_NAME, true);
      left_chars = logging_rate_.to_string(left_chars, indent_level + 2, LOGGING_RATE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint32 sector_address_ = 0U;
      EmbeddedProto::uint32 logging_rate_ = 0U;

};

class Imu final: public ::EmbeddedProto::MessageInterface
{
  public:
    Imu() = default;
    Imu(const Imu& rhs )
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
    }

    Imu(const Imu&& rhs ) noexcept
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
    }

    ~Imu() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ACCEL_X = 1,
      ACCEL_Y = 2,
      ACCEL_Z = 3,
      GYRO_X = 4,
      GYRO_Y = 5,
      GYRO_Z = 6,
      MAG_X = 7,
      MAG_Y = 8,
      MAG_Z = 9
    };

    Imu& operator=(const Imu& rhs)
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      return *this;
    }

    Imu& operator=(const Imu&& rhs) noexcept
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      return *this;
    }

    static constexpr char const* ACCEL_X_NAME = "accel_x";
    inline void clear_accel_x() { accel_x_.clear(); }
    inline void set_accel_x(const int32_t& value) { accel_x_ = value; }
    inline void set_accel_x(const int32_t&& value) { accel_x_ = value; }
    inline int32_t& mutable_accel_x() { return accel_x_.get(); }
    inline const int32_t& get_accel_x() const { return accel_x_.get(); }
    inline int32_t accel_x() const { return accel_x_.get(); }

    static constexpr char const* ACCEL_Y_NAME = "accel_y";
    inline void clear_accel_y() { accel_y_.clear(); }
    inline void set_accel_y(const int32_t& value) { accel_y_ = value; }
    inline void set_accel_y(const int32_t&& value) { accel_y_ = value; }
    inline int32_t& mutable_accel_y() { return accel_y_.get(); }
    inline const int32_t& get_accel_y() const { return accel_y_.get(); }
    inline int32_t accel_y() const { return accel_y_.get(); }

    static constexpr char const* ACCEL_Z_NAME = "accel_z";
    inline void clear_accel_z() { accel_z_.clear(); }
    inline void set_accel_z(const int32_t& value) { accel_z_ = value; }
    inline void set_accel_z(const int32_t&& value) { accel_z_ = value; }
    inline int32_t& mutable_accel_z() { return accel_z_.get(); }
    inline const int32_t& get_accel_z() const { return accel_z_.get(); }
    inline int32_t accel_z() const { return accel_z_.get(); }

    static constexpr char const* GYRO_X_NAME = "gyro_x";
    inline void clear_gyro_x() { gyro_x_.clear(); }
    inline void set_gyro_x(const int32_t& value) { gyro_x_ = value; }
    inline void set_gyro_x(const int32_t&& value) { gyro_x_ = value; }
    inline int32_t& mutable_gyro_x() { return gyro_x_.get(); }
    inline const int32_t& get_gyro_x() const { return gyro_x_.get(); }
    inline int32_t gyro_x() const { return gyro_x_.get(); }

    static constexpr char const* GYRO_Y_NAME = "gyro_y";
    inline void clear_gyro_y() { gyro_y_.clear(); }
    inline void set_gyro_y(const int32_t& value) { gyro_y_ = value; }
    inline void set_gyro_y(const int32_t&& value) { gyro_y_ = value; }
    inline int32_t& mutable_gyro_y() { return gyro_y_.get(); }
    inline const int32_t& get_gyro_y() const { return gyro_y_.get(); }
    inline int32_t gyro_y() const { return gyro_y_.get(); }

    static constexpr char const* GYRO_Z_NAME = "gyro_z";
    inline void clear_gyro_z() { gyro_z_.clear(); }
    inline void set_gyro_z(const int32_t& value) { gyro_z_ = value; }
    inline void set_gyro_z(const int32_t&& value) { gyro_z_ = value; }
    inline int32_t& mutable_gyro_z() { return gyro_z_.get(); }
    inline const int32_t& get_gyro_z() const { return gyro_z_.get(); }
    inline int32_t gyro_z() const { return gyro_z_.get(); }

    static constexpr char const* MAG_X_NAME = "mag_x";
    inline void clear_mag_x() { mag_x_.clear(); }
    inline void set_mag_x(const int32_t& value) { mag_x_ = value; }
    inline void set_mag_x(const int32_t&& value) { mag_x_ = value; }
    inline int32_t& mutable_mag_x() { return mag_x_.get(); }
    inline const int32_t& get_mag_x() const { return mag_x_.get(); }
    inline int32_t mag_x() const { return mag_x_.get(); }

    static constexpr char const* MAG_Y_NAME = "mag_y";
    inline void clear_mag_y() { mag_y_.clear(); }
    inline void set_mag_y(const int32_t& value) { mag_y_ = value; }
    inline void set_mag_y(const int32_t&& value) { mag_y_ = value; }
    inline int32_t& mutable_mag_y() { return mag_y_.get(); }
    inline const int32_t& get_mag_y() const { return mag_y_.get(); }
    inline int32_t mag_y() const { return mag_y_.get(); }

    static constexpr char const* MAG_Z_NAME = "mag_z";
    inline void clear_mag_z() { mag_z_.clear(); }
    inline void set_mag_z(const int32_t& value) { mag_z_ = value; }
    inline void set_mag_z(const int32_t&& value) { mag_z_ = value; }
    inline int32_t& mutable_mag_z() { return mag_z_.get(); }
    inline const int32_t& get_mag_z() const { return mag_z_.get(); }
    inline int32_t mag_z() const { return mag_z_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != accel_x_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = accel_x_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACCEL_X), buffer, false);
      }

      if((0 != accel_y_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = accel_y_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACCEL_Y), buffer, false);
      }

      if((0 != accel_z_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = accel_z_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACCEL_Z), buffer, false);
      }

      if((0 != gyro_x_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = gyro_x_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GYRO_X), buffer, false);
      }

      if((0 != gyro_y_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = gyro_y_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GYRO_Y), buffer, false);
      }

      if((0 != gyro_z_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = gyro_z_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GYRO_Z), buffer, false);
      }

      if((0 != mag_x_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = mag_x_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MAG_X), buffer, false);
      }

      if((0 != mag_y_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = mag_y_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MAG_Y), buffer, false);
      }

      if((0 != mag_z_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = mag_z_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MAG_Z), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ACCEL_X:
            return_value = accel_x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ACCEL_Y:
            return_value = accel_y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ACCEL_Z:
            return_value = accel_z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GYRO_X:
            return_value = gyro_x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GYRO_Y:
            return_value = gyro_y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GYRO_Z:
            return_value = gyro_z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MAG_X:
            return_value = mag_x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MAG_Y:
            return_value = mag_y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MAG_Z:
            return_value = mag_z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_accel_x();
      clear_accel_y();
      clear_accel_z();
      clear_gyro_x();
      clear_gyro_y();
      clear_gyro_z();
      clear_mag_x();
      clear_mag_y();
      clear_mag_z();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ACCEL_X:
          name = ACCEL_X_NAME;
          break;
        case FieldNumber::ACCEL_Y:
          name = ACCEL_Y_NAME;
          break;
        case FieldNumber::ACCEL_Z:
          name = ACCEL_Z_NAME;
          break;
        case FieldNumber::GYRO_X:
          name = GYRO_X_NAME;
          break;
        case FieldNumber::GYRO_Y:
          name = GYRO_Y_NAME;
          break;
        case FieldNumber::GYRO_Z:
          name = GYRO_Z_NAME;
          break;
        case FieldNumber::MAG_X:
          name = MAG_X_NAME;
          break;
        case FieldNumber::MAG_Y:
          name = MAG_Y_NAME;
          break;
        case FieldNumber::MAG_Z:
          name = MAG_Z_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = accel_x_.to_string(left_chars, indent_level + 2, ACCEL_X_NAME, true);
      left_chars = accel_y_.to_string(left_chars, indent_level + 2, ACCEL_Y_NAME, false);
      left_chars = accel_z_.to_string(left_chars, indent_level + 2, ACCEL_Z_NAME, false);
      left_chars = gyro_x_.to_string(left_chars, indent_level + 2, GYRO_X_NAME, false);
      left_chars = gyro_y_.to_string(left_chars, indent_level + 2, GYRO_Y_NAME, false);
      left_chars = gyro_z_.to_string(left_chars, indent_level + 2, GYRO_Z_NAME, false);
      left_chars = mag_x_.to_string(left_chars, indent_level + 2, MAG_X_NAME, false);
      left_chars = mag_y_.to_string(left_chars, indent_level + 2, MAG_Y_NAME, false);
      left_chars = mag_z_.to_string(left_chars, indent_level + 2, MAG_Z_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 accel_x_ = 0;
      EmbeddedProto::int32 accel_y_ = 0;
      EmbeddedProto::int32 accel_z_ = 0;
      EmbeddedProto::int32 gyro_x_ = 0;
      EmbeddedProto::int32 gyro_y_ = 0;
      EmbeddedProto::int32 gyro_z_ = 0;
      EmbeddedProto::int32 mag_x_ = 0;
      EmbeddedProto::int32 mag_y_ = 0;
      EmbeddedProto::int32 mag_z_ = 0;

};

class LaunchRailLoadCell final: public ::EmbeddedProto::MessageInterface
{
  public:
    LaunchRailLoadCell() = default;
    LaunchRailLoadCell(const LaunchRailLoadCell& rhs )
    {
      set_rocket_mass(rhs.get_rocket_mass());
    }

    LaunchRailLoadCell(const LaunchRailLoadCell&& rhs ) noexcept
    {
      set_rocket_mass(rhs.get_rocket_mass());
    }

    ~LaunchRailLoadCell() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ROCKET_MASS = 1
    };

    LaunchRailLoadCell& operator=(const LaunchRailLoadCell& rhs)
    {
      set_rocket_mass(rhs.get_rocket_mass());
      return *this;
    }

    LaunchRailLoadCell& operator=(const LaunchRailLoadCell&& rhs) noexcept
    {
      set_rocket_mass(rhs.get_rocket_mass());
      return *this;
    }

    static constexpr char const* ROCKET_MASS_NAME = "rocket_mass";
    inline void clear_rocket_mass() { rocket_mass_.clear(); }
    inline void set_rocket_mass(const int32_t& value) { rocket_mass_ = value; }
    inline void set_rocket_mass(const int32_t&& value) { rocket_mass_ = value; }
    inline int32_t& mutable_rocket_mass() { return rocket_mass_.get(); }
    inline const int32_t& get_rocket_mass() const { return rocket_mass_.get(); }
    inline int32_t rocket_mass() const { return rocket_mass_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != rocket_mass_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = rocket_mass_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ROCKET_MASS), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::ROCKET_MASS:
            return_value = rocket_mass_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_rocket_mass();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::ROCKET_MASS:
          name = ROCKET_MASS_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = rocket_mass_.to_string(left_chars, indent_level + 2, ROCKET_MASS_NAME, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 rocket_mass_ = 0;

};

class NosLoadCell final: public ::EmbeddedProto::MessageInterface
{
  public:
    NosLoadCell() = default;
    NosLoadCell(const NosLoadCell& rhs )
    {
      set_nos1_mass(rhs.get_nos1_mass());
      set_nos2_mass(rhs.get_nos2_mass());
    }

    NosLoadCell(const NosLoadCell&& rhs ) noexcept
    {
      set_nos1_mass(rhs.get_nos1_mass());
      set_nos2_mass(rhs.get_nos2_mass());
    }

    ~NosLoadCell() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      NOS1_MASS = 1,
      NOS2_MASS = 2
    };

    NosLoadCell& operator=(const NosLoadCell& rhs)
    {
      set_nos1_mass(rhs.get_nos1_mass());
      set_nos2_mass(rhs.get_nos2_mass());
      return *this;
    }

    NosLoadCell& operator=(const NosLoadCell&& rhs) noexcept
    {
      set_nos1_mass(rhs.get_nos1_mass());
      set_nos2_mass(rhs.get_nos2_mass());
      return *this;
    }

    static constexpr char const* NOS1_MASS_NAME = "nos1_mass";
    inline void clear_nos1_mass() { nos1_mass_.clear(); }
    inline void set_nos1_mass(const int32_t& value) { nos1_mass_ = value; }
    inline void set_nos1_mass(const int32_t&& value) { nos1_mass_ = value; }
    inline int32_t& mutable_nos1_mass() { return nos1_mass_.get(); }
    inline const int32_t& get_nos1_mass() const { return nos1_mass_.get(); }
    inline int32_t nos1_mass() const { return nos1_mass_.get(); }

    static constexpr char const* NOS2_MASS_NAME = "nos2_mass";
    inline void clear_nos2_mass() { nos2_mass_.clear(); }
    inline void set_nos2_mass(const int32_t& value) { nos2_mass_ = value; }
    inline void set_nos2_mass(const int32_t&& value) { nos2_mass_ = value; }
    inline int32_t& mutable_nos2_mass() { return nos2_mass_.get(); }
    inline const int32_t& get_nos2_mass() const { return nos2_mass_.get(); }
    inline int32_t nos2_mass() const { return nos2_mass_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != nos1_mass_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = nos1_mass_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NOS1_MASS), buffer, false);
      }

      if((0 != nos2_mass_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = nos2_mass_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NOS2_MASS), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::NOS1_MASS:
            return_value = nos1_mass_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOS2_MASS:
            return_value = nos2_mass_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_nos1_mass();
      clear_nos2_mass();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::NOS1_MASS:
          name = NOS1_MASS_NAME;
          break;
        case FieldNumber::NOS2_MASS:
          name = NOS2_MASS_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = nos1_mass_.to_string(left_chars, indent_level + 2, NOS1_MASS_NAME, true);
      left_chars = nos2_mass_.to_string(left_chars, indent_level + 2, NOS2_MASS_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 nos1_mass_ = 0;
      EmbeddedProto::int32 nos2_mass_ = 0;

};

class PadBoxStatus final: public ::EmbeddedProto::MessageInterface
{
  public:
    PadBoxStatus() = default;
    PadBoxStatus(const PadBoxStatus& rhs )
    {
      set_continuity_1(rhs.get_continuity_1());
      set_continuity_2(rhs.get_continuity_2());
      set_box1_on(rhs.get_box1_on());
      set_box2_on(rhs.get_box2_on());
    }

    PadBoxStatus(const PadBoxStatus&& rhs ) noexcept
    {
      set_continuity_1(rhs.get_continuity_1());
      set_continuity_2(rhs.get_continuity_2());
      set_box1_on(rhs.get_box1_on());
      set_box2_on(rhs.get_box2_on());
    }

    ~PadBoxStatus() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      CONTINUITY_1 = 1,
      CONTINUITY_2 = 2,
      BOX1_ON = 3,
      BOX2_ON = 4
    };

    PadBoxStatus& operator=(const PadBoxStatus& rhs)
    {
      set_continuity_1(rhs.get_continuity_1());
      set_continuity_2(rhs.get_continuity_2());
      set_box1_on(rhs.get_box1_on());
      set_box2_on(rhs.get_box2_on());
      return *this;
    }

    PadBoxStatus& operator=(const PadBoxStatus&& rhs) noexcept
    {
      set_continuity_1(rhs.get_continuity_1());
      set_continuity_2(rhs.get_continuity_2());
      set_box1_on(rhs.get_box1_on());
      set_box2_on(rhs.get_box2_on());
      return *this;
    }

    static constexpr char const* CONTINUITY_1_NAME = "continuity_1";
    inline void clear_continuity_1() { continuity_1_.clear(); }
    inline void set_continuity_1(const bool& value) { continuity_1_ = value; }
    inline void set_continuity_1(const bool&& value) { continuity_1_ = value; }
    inline bool& mutable_continuity_1() { return continuity_1_.get(); }
    inline const bool& get_continuity_1() const { return continuity_1_.get(); }
    inline bool continuity_1() const { return continuity_1_.get(); }

    static constexpr char const* CONTINUITY_2_NAME = "continuity_2";
    inline void clear_continuity_2() { continuity_2_.clear(); }
    inline void set_continuity_2(const bool& value) { continuity_2_ = value; }
    inline void set_continuity_2(const bool&& value) { continuity_2_ = value; }
    inline bool& mutable_continuity_2() { return continuity_2_.get(); }
    inline const bool& get_continuity_2() const { return continuity_2_.get(); }
    inline bool continuity_2() const { return continuity_2_.get(); }

    static constexpr char const* BOX1_ON_NAME = "box1_on";
    inline void clear_box1_on() { box1_on_.clear(); }
    inline void set_box1_on(const bool& value) { box1_on_ = value; }
    inline void set_box1_on(const bool&& value) { box1_on_ = value; }
    inline bool& mutable_box1_on() { return box1_on_.get(); }
    inline const bool& get_box1_on() const { return box1_on_.get(); }
    inline bool box1_on() const { return box1_on_.get(); }

    static constexpr char const* BOX2_ON_NAME = "box2_on";
    inline void clear_box2_on() { box2_on_.clear(); }
    inline void set_box2_on(const bool& value) { box2_on_ = value; }
    inline void set_box2_on(const bool&& value) { box2_on_ = value; }
    inline bool& mutable_box2_on() { return box2_on_.get(); }
    inline const bool& get_box2_on() const { return box2_on_.get(); }
    inline bool box2_on() const { return box2_on_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((false != continuity_1_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = continuity_1_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CONTINUITY_1), buffer, false);
      }

      if((false != continuity_2_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = continuity_2_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CONTINUITY_2), buffer, false);
      }

      if((false != box1_on_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = box1_on_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BOX1_ON), buffer, false);
      }

      if((false != box2_on_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = box2_on_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BOX2_ON), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::CONTINUITY_1:
            return_value = continuity_1_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::CONTINUITY_2:
            return_value = continuity_2_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::BOX1_ON:
            return_value = box1_on_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::BOX2_ON:
            return_value = box2_on_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_continuity_1();
      clear_continuity_2();
      clear_box1_on();
      clear_box2_on();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::CONTINUITY_1:
          name = CONTINUITY_1_NAME;
          break;
        case FieldNumber::CONTINUITY_2:
          name = CONTINUITY_2_NAME;
          break;
        case FieldNumber::BOX1_ON:
          name = BOX1_ON_NAME;
          break;
        case FieldNumber::BOX2_ON:
          name = BOX2_ON_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = continuity_1_.to_string(left_chars, indent_level + 2, CONTINUITY_1_NAME, true);
      left_chars = continuity_2_.to_string(left_chars, indent_level + 2, CONTINUITY_2_NAME, false);
      left_chars = box1_on_.to_string(left_chars, indent_level + 2, BOX1_ON_NAME, false);
      left_chars = box2_on_.to_string(left_chars, indent_level + 2, BOX2_ON_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::boolean continuity_1_ = false;
      EmbeddedProto::boolean continuity_2_ = false;
      EmbeddedProto::boolean box1_on_ = false;
      EmbeddedProto::boolean box2_on_ = false;

};

class PbbPressure final: public ::EmbeddedProto::MessageInterface
{
  public:
    PbbPressure() = default;
    PbbPressure(const PbbPressure& rhs )
    {
      set_ib_pressure(rhs.get_ib_pressure());
      set_lower_pv_pressure(rhs.get_lower_pv_pressure());
    }

    PbbPressure(const PbbPressure&& rhs ) noexcept
    {
      set_ib_pressure(rhs.get_ib_pressure());
      set_lower_pv_pressure(rhs.get_lower_pv_pressure());
    }

    ~PbbPressure() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      IB_PRESSURE = 1,
      LOWER_PV_PRESSURE = 2
    };

    PbbPressure& operator=(const PbbPressure& rhs)
    {
      set_ib_pressure(rhs.get_ib_pressure());
      set_lower_pv_pressure(rhs.get_lower_pv_pressure());
      return *this;
    }

    PbbPressure& operator=(const PbbPressure&& rhs) noexcept
    {
      set_ib_pressure(rhs.get_ib_pressure());
      set_lower_pv_pressure(rhs.get_lower_pv_pressure());
      return *this;
    }

    static constexpr char const* IB_PRESSURE_NAME = "ib_pressure";
    inline void clear_ib_pressure() { ib_pressure_.clear(); }
    inline void set_ib_pressure(const int32_t& value) { ib_pressure_ = value; }
    inline void set_ib_pressure(const int32_t&& value) { ib_pressure_ = value; }
    inline int32_t& mutable_ib_pressure() { return ib_pressure_.get(); }
    inline const int32_t& get_ib_pressure() const { return ib_pressure_.get(); }
    inline int32_t ib_pressure() const { return ib_pressure_.get(); }

    static constexpr char const* LOWER_PV_PRESSURE_NAME = "lower_pv_pressure";
    inline void clear_lower_pv_pressure() { lower_pv_pressure_.clear(); }
    inline void set_lower_pv_pressure(const int32_t& value) { lower_pv_pressure_ = value; }
    inline void set_lower_pv_pressure(const int32_t&& value) { lower_pv_pressure_ = value; }
    inline int32_t& mutable_lower_pv_pressure() { return lower_pv_pressure_.get(); }
    inline const int32_t& get_lower_pv_pressure() const { return lower_pv_pressure_.get(); }
    inline int32_t lower_pv_pressure() const { return lower_pv_pressure_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != ib_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = ib_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IB_PRESSURE), buffer, false);
      }

      if((0 != lower_pv_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = lower_pv_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOWER_PV_PRESSURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::IB_PRESSURE:
            return_value = ib_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOWER_PV_PRESSURE:
            return_value = lower_pv_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_ib_pressure();
      clear_lower_pv_pressure();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::IB_PRESSURE:
          name = IB_PRESSURE_NAME;
          break;
        case FieldNumber::LOWER_PV_PRESSURE:
          name = LOWER_PV_PRESSURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = ib_pressure_.to_string(left_chars, indent_level + 2, IB_PRESSURE_NAME, true);
      left_chars = lower_pv_pressure_.to_string(left_chars, indent_level + 2, LOWER_PV_PRESSURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 ib_pressure_ = 0;
      EmbeddedProto::int32 lower_pv_pressure_ = 0;

};

class PbbTemperature final: public ::EmbeddedProto::MessageInterface
{
  public:
    PbbTemperature() = default;
    PbbTemperature(const PbbTemperature& rhs )
    {
      set_ib_temperature(rhs.get_ib_temperature());
      set_pv_temperature(rhs.get_pv_temperature());
    }

    PbbTemperature(const PbbTemperature&& rhs ) noexcept
    {
      set_ib_temperature(rhs.get_ib_temperature());
      set_pv_temperature(rhs.get_pv_temperature());
    }

    ~PbbTemperature() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      IB_TEMPERATURE = 1,
      PV_TEMPERATURE = 2
    };

    PbbTemperature& operator=(const PbbTemperature& rhs)
    {
      set_ib_temperature(rhs.get_ib_temperature());
      set_pv_temperature(rhs.get_pv_temperature());
      return *this;
    }

    PbbTemperature& operator=(const PbbTemperature&& rhs) noexcept
    {
      set_ib_temperature(rhs.get_ib_temperature());
      set_pv_temperature(rhs.get_pv_temperature());
      return *this;
    }

    static constexpr char const* IB_TEMPERATURE_NAME = "ib_temperature";
    inline void clear_ib_temperature() { ib_temperature_.clear(); }
    inline void set_ib_temperature(const int32_t& value) { ib_temperature_ = value; }
    inline void set_ib_temperature(const int32_t&& value) { ib_temperature_ = value; }
    inline int32_t& mutable_ib_temperature() { return ib_temperature_.get(); }
    inline const int32_t& get_ib_temperature() const { return ib_temperature_.get(); }
    inline int32_t ib_temperature() const { return ib_temperature_.get(); }

    static constexpr char const* PV_TEMPERATURE_NAME = "pv_temperature";
    inline void clear_pv_temperature() { pv_temperature_.clear(); }
    inline void set_pv_temperature(const int32_t& value) { pv_temperature_ = value; }
    inline void set_pv_temperature(const int32_t&& value) { pv_temperature_ = value; }
    inline int32_t& mutable_pv_temperature() { return pv_temperature_.get(); }
    inline const int32_t& get_pv_temperature() const { return pv_temperature_.get(); }
    inline int32_t pv_temperature() const { return pv_temperature_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != ib_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = ib_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IB_TEMPERATURE), buffer, false);
      }

      if((0 != pv_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pv_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PV_TEMPERATURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::IB_TEMPERATURE:
            return_value = ib_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PV_TEMPERATURE:
            return_value = pv_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_ib_temperature();
      clear_pv_temperature();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::IB_TEMPERATURE:
          name = IB_TEMPERATURE_NAME;
          break;
        case FieldNumber::PV_TEMPERATURE:
          name = PV_TEMPERATURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = ib_temperature_.to_string(left_chars, indent_level + 2, IB_TEMPERATURE_NAME, true);
      left_chars = pv_temperature_.to_string(left_chars, indent_level + 2, PV_TEMPERATURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 ib_temperature_ = 0;
      EmbeddedProto::int32 pv_temperature_ = 0;

};

class PressureLog final: public ::EmbeddedProto::MessageInterface
{
  public:
    PressureLog() = default;
    PressureLog(const PressureLog& rhs )
    {
      set_time(rhs.get_time());
      set_pv_pressure(rhs.get_pv_pressure());
      set_ib_pressure(rhs.get_ib_pressure());
    }

    PressureLog(const PressureLog&& rhs ) noexcept
    {
      set_time(rhs.get_time());
      set_pv_pressure(rhs.get_pv_pressure());
      set_ib_pressure(rhs.get_ib_pressure());
    }

    ~PressureLog() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TIME = 1,
      PV_PRESSURE = 2,
      IB_PRESSURE = 3
    };

    PressureLog& operator=(const PressureLog& rhs)
    {
      set_time(rhs.get_time());
      set_pv_pressure(rhs.get_pv_pressure());
      set_ib_pressure(rhs.get_ib_pressure());
      return *this;
    }

    PressureLog& operator=(const PressureLog&& rhs) noexcept
    {
      set_time(rhs.get_time());
      set_pv_pressure(rhs.get_pv_pressure());
      set_ib_pressure(rhs.get_ib_pressure());
      return *this;
    }

    static constexpr char const* TIME_NAME = "time";
    inline void clear_time() { time_.clear(); }
    inline void set_time(const uint32_t& value) { time_ = value; }
    inline void set_time(const uint32_t&& value) { time_ = value; }
    inline uint32_t& mutable_time() { return time_.get(); }
    inline const uint32_t& get_time() const { return time_.get(); }
    inline uint32_t time() const { return time_.get(); }

    static constexpr char const* PV_PRESSURE_NAME = "pv_pressure";
    inline void clear_pv_pressure() { pv_pressure_.clear(); }
    inline void set_pv_pressure(const int32_t& value) { pv_pressure_ = value; }
    inline void set_pv_pressure(const int32_t&& value) { pv_pressure_ = value; }
    inline int32_t& mutable_pv_pressure() { return pv_pressure_.get(); }
    inline const int32_t& get_pv_pressure() const { return pv_pressure_.get(); }
    inline int32_t pv_pressure() const { return pv_pressure_.get(); }

    static constexpr char const* IB_PRESSURE_NAME = "ib_pressure";
    inline void clear_ib_pressure() { ib_pressure_.clear(); }
    inline void set_ib_pressure(const int32_t& value) { ib_pressure_ = value; }
    inline void set_ib_pressure(const int32_t&& value) { ib_pressure_ = value; }
    inline int32_t& mutable_ib_pressure() { return ib_pressure_.get(); }
    inline const int32_t& get_ib_pressure() const { return ib_pressure_.get(); }
    inline int32_t ib_pressure() const { return ib_pressure_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != time_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = time_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIME), buffer, false);
      }

      if((0 != pv_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pv_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PV_PRESSURE), buffer, false);
      }

      if((0 != ib_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = ib_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IB_PRESSURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TIME:
            return_value = time_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PV_PRESSURE:
            return_value = pv_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::IB_PRESSURE:
            return_value = ib_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_time();
      clear_pv_pressure();
      clear_ib_pressure();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TIME:
          name = TIME_NAME;
          break;
        case FieldNumber::PV_PRESSURE:
          name = PV_PRESSURE_NAME;
          break;
        case FieldNumber::IB_PRESSURE:
          name = IB_PRESSURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = time_.to_string(left_chars, indent_level + 2, TIME_NAME, true);
      left_chars = pv_pressure_.to_string(left_chars, indent_level + 2, PV_PRESSURE_NAME, false);
      left_chars = ib_pressure_.to_string(left_chars, indent_level + 2, IB_PRESSURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint32 time_ = 0U;
      EmbeddedProto::int32 pv_pressure_ = 0;
      EmbeddedProto::int32 ib_pressure_ = 0;

};

class RcuPressure final: public ::EmbeddedProto::MessageInterface
{
  public:
    RcuPressure() = default;
    RcuPressure(const RcuPressure& rhs )
    {
      set_pt1_pressure(rhs.get_pt1_pressure());
      set_pt2_pressure(rhs.get_pt2_pressure());
      set_pt3_pressure(rhs.get_pt3_pressure());
      set_pt4_pressure(rhs.get_pt4_pressure());
    }

    RcuPressure(const RcuPressure&& rhs ) noexcept
    {
      set_pt1_pressure(rhs.get_pt1_pressure());
      set_pt2_pressure(rhs.get_pt2_pressure());
      set_pt3_pressure(rhs.get_pt3_pressure());
      set_pt4_pressure(rhs.get_pt4_pressure());
    }

    ~RcuPressure() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      PT1_PRESSURE = 1,
      PT2_PRESSURE = 2,
      PT3_PRESSURE = 3,
      PT4_PRESSURE = 4
    };

    RcuPressure& operator=(const RcuPressure& rhs)
    {
      set_pt1_pressure(rhs.get_pt1_pressure());
      set_pt2_pressure(rhs.get_pt2_pressure());
      set_pt3_pressure(rhs.get_pt3_pressure());
      set_pt4_pressure(rhs.get_pt4_pressure());
      return *this;
    }

    RcuPressure& operator=(const RcuPressure&& rhs) noexcept
    {
      set_pt1_pressure(rhs.get_pt1_pressure());
      set_pt2_pressure(rhs.get_pt2_pressure());
      set_pt3_pressure(rhs.get_pt3_pressure());
      set_pt4_pressure(rhs.get_pt4_pressure());
      return *this;
    }

    static constexpr char const* PT1_PRESSURE_NAME = "pt1_pressure";
    inline void clear_pt1_pressure() { pt1_pressure_.clear(); }
    inline void set_pt1_pressure(const int32_t& value) { pt1_pressure_ = value; }
    inline void set_pt1_pressure(const int32_t&& value) { pt1_pressure_ = value; }
    inline int32_t& mutable_pt1_pressure() { return pt1_pressure_.get(); }
    inline const int32_t& get_pt1_pressure() const { return pt1_pressure_.get(); }
    inline int32_t pt1_pressure() const { return pt1_pressure_.get(); }

    static constexpr char const* PT2_PRESSURE_NAME = "pt2_pressure";
    inline void clear_pt2_pressure() { pt2_pressure_.clear(); }
    inline void set_pt2_pressure(const int32_t& value) { pt2_pressure_ = value; }
    inline void set_pt2_pressure(const int32_t&& value) { pt2_pressure_ = value; }
    inline int32_t& mutable_pt2_pressure() { return pt2_pressure_.get(); }
    inline const int32_t& get_pt2_pressure() const { return pt2_pressure_.get(); }
    inline int32_t pt2_pressure() const { return pt2_pressure_.get(); }

    static constexpr char const* PT3_PRESSURE_NAME = "pt3_pressure";
    inline void clear_pt3_pressure() { pt3_pressure_.clear(); }
    inline void set_pt3_pressure(const int32_t& value) { pt3_pressure_ = value; }
    inline void set_pt3_pressure(const int32_t&& value) { pt3_pressure_ = value; }
    inline int32_t& mutable_pt3_pressure() { return pt3_pressure_.get(); }
    inline const int32_t& get_pt3_pressure() const { return pt3_pressure_.get(); }
    inline int32_t pt3_pressure() const { return pt3_pressure_.get(); }

    static constexpr char const* PT4_PRESSURE_NAME = "pt4_pressure";
    inline void clear_pt4_pressure() { pt4_pressure_.clear(); }
    inline void set_pt4_pressure(const int32_t& value) { pt4_pressure_ = value; }
    inline void set_pt4_pressure(const int32_t&& value) { pt4_pressure_ = value; }
    inline int32_t& mutable_pt4_pressure() { return pt4_pressure_.get(); }
    inline const int32_t& get_pt4_pressure() const { return pt4_pressure_.get(); }
    inline int32_t pt4_pressure() const { return pt4_pressure_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != pt1_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pt1_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PT1_PRESSURE), buffer, false);
      }

      if((0 != pt2_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pt2_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PT2_PRESSURE), buffer, false);
      }

      if((0 != pt3_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pt3_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PT3_PRESSURE), buffer, false);
      }

      if((0 != pt4_pressure_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pt4_pressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PT4_PRESSURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::PT1_PRESSURE:
            return_value = pt1_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PT2_PRESSURE:
            return_value = pt2_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PT3_PRESSURE:
            return_value = pt3_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PT4_PRESSURE:
            return_value = pt4_pressure_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_pt1_pressure();
      clear_pt2_pressure();
      clear_pt3_pressure();
      clear_pt4_pressure();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::PT1_PRESSURE:
          name = PT1_PRESSURE_NAME;
          break;
        case FieldNumber::PT2_PRESSURE:
          name = PT2_PRESSURE_NAME;
          break;
        case FieldNumber::PT3_PRESSURE:
          name = PT3_PRESSURE_NAME;
          break;
        case FieldNumber::PT4_PRESSURE:
          name = PT4_PRESSURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = pt1_pressure_.to_string(left_chars, indent_level + 2, PT1_PRESSURE_NAME, true);
      left_chars = pt2_pressure_.to_string(left_chars, indent_level + 2, PT2_PRESSURE_NAME, false);
      left_chars = pt3_pressure_.to_string(left_chars, indent_level + 2, PT3_PRESSURE_NAME, false);
      left_chars = pt4_pressure_.to_string(left_chars, indent_level + 2, PT4_PRESSURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 pt1_pressure_ = 0;
      EmbeddedProto::int32 pt2_pressure_ = 0;
      EmbeddedProto::int32 pt3_pressure_ = 0;
      EmbeddedProto::int32 pt4_pressure_ = 0;

};

class RcuTemperature final: public ::EmbeddedProto::MessageInterface
{
  public:
    RcuTemperature() = default;
    RcuTemperature(const RcuTemperature& rhs )
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
    }

    RcuTemperature(const RcuTemperature&& rhs ) noexcept
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
    }

    ~RcuTemperature() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TC1_TEMPERATURE = 1,
      TC2_TEMPERATURE = 2
    };

    RcuTemperature& operator=(const RcuTemperature& rhs)
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
      return *this;
    }

    RcuTemperature& operator=(const RcuTemperature&& rhs) noexcept
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
      return *this;
    }

    static constexpr char const* TC1_TEMPERATURE_NAME = "tc1_temperature";
    inline void clear_tc1_temperature() { tc1_temperature_.clear(); }
    inline void set_tc1_temperature(const int32_t& value) { tc1_temperature_ = value; }
    inline void set_tc1_temperature(const int32_t&& value) { tc1_temperature_ = value; }
    inline int32_t& mutable_tc1_temperature() { return tc1_temperature_.get(); }
    inline const int32_t& get_tc1_temperature() const { return tc1_temperature_.get(); }
    inline int32_t tc1_temperature() const { return tc1_temperature_.get(); }

    static constexpr char const* TC2_TEMPERATURE_NAME = "tc2_temperature";
    inline void clear_tc2_temperature() { tc2_temperature_.clear(); }
    inline void set_tc2_temperature(const int32_t& value) { tc2_temperature_ = value; }
    inline void set_tc2_temperature(const int32_t&& value) { tc2_temperature_ = value; }
    inline int32_t& mutable_tc2_temperature() { return tc2_temperature_.get(); }
    inline const int32_t& get_tc2_temperature() const { return tc2_temperature_.get(); }
    inline int32_t tc2_temperature() const { return tc2_temperature_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != tc1_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = tc1_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TC1_TEMPERATURE), buffer, false);
      }

      if((0 != tc2_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = tc2_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TC2_TEMPERATURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TC1_TEMPERATURE:
            return_value = tc1_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TC2_TEMPERATURE:
            return_value = tc2_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_tc1_temperature();
      clear_tc2_temperature();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TC1_TEMPERATURE:
          name = TC1_TEMPERATURE_NAME;
          break;
        case FieldNumber::TC2_TEMPERATURE:
          name = TC2_TEMPERATURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = tc1_temperature_.to_string(left_chars, indent_level + 2, TC1_TEMPERATURE_NAME, true);
      left_chars = tc2_temperature_.to_string(left_chars, indent_level + 2, TC2_TEMPERATURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 tc1_temperature_ = 0;
      EmbeddedProto::int32 tc2_temperature_ = 0;

};

class RelayStatus final: public ::EmbeddedProto::MessageInterface
{
  public:
    RelayStatus() = default;
    RelayStatus(const RelayStatus& rhs )
    {
      set_ac1_open(rhs.get_ac1_open());
      set_ac2_open(rhs.get_ac2_open());
      set_pbv1_open(rhs.get_pbv1_open());
      set_pbv2_open(rhs.get_pbv2_open());
      set_pbv3_open(rhs.get_pbv3_open());
      set_pbv4_open(rhs.get_pbv4_open());
      set_sol5_open(rhs.get_sol5_open());
      set_sol6_open(rhs.get_sol6_open());
      set_sol7_open(rhs.get_sol7_open());
      set_sol8a_open(rhs.get_sol8a_open());
      set_sol8b_open(rhs.get_sol8b_open());
    }

    RelayStatus(const RelayStatus&& rhs ) noexcept
    {
      set_ac1_open(rhs.get_ac1_open());
      set_ac2_open(rhs.get_ac2_open());
      set_pbv1_open(rhs.get_pbv1_open());
      set_pbv2_open(rhs.get_pbv2_open());
      set_pbv3_open(rhs.get_pbv3_open());
      set_pbv4_open(rhs.get_pbv4_open());
      set_sol5_open(rhs.get_sol5_open());
      set_sol6_open(rhs.get_sol6_open());
      set_sol7_open(rhs.get_sol7_open());
      set_sol8a_open(rhs.get_sol8a_open());
      set_sol8b_open(rhs.get_sol8b_open());
    }

    ~RelayStatus() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      AC1_OPEN = 1,
      AC2_OPEN = 2,
      PBV1_OPEN = 3,
      PBV2_OPEN = 4,
      PBV3_OPEN = 5,
      PBV4_OPEN = 6,
      SOL5_OPEN = 10,
      SOL6_OPEN = 11,
      SOL7_OPEN = 12,
      SOL8A_OPEN = 13,
      SOL8B_OPEN = 14
    };

    RelayStatus& operator=(const RelayStatus& rhs)
    {
      set_ac1_open(rhs.get_ac1_open());
      set_ac2_open(rhs.get_ac2_open());
      set_pbv1_open(rhs.get_pbv1_open());
      set_pbv2_open(rhs.get_pbv2_open());
      set_pbv3_open(rhs.get_pbv3_open());
      set_pbv4_open(rhs.get_pbv4_open());
      set_sol5_open(rhs.get_sol5_open());
      set_sol6_open(rhs.get_sol6_open());
      set_sol7_open(rhs.get_sol7_open());
      set_sol8a_open(rhs.get_sol8a_open());
      set_sol8b_open(rhs.get_sol8b_open());
      return *this;
    }

    RelayStatus& operator=(const RelayStatus&& rhs) noexcept
    {
      set_ac1_open(rhs.get_ac1_open());
      set_ac2_open(rhs.get_ac2_open());
      set_pbv1_open(rhs.get_pbv1_open());
      set_pbv2_open(rhs.get_pbv2_open());
      set_pbv3_open(rhs.get_pbv3_open());
      set_pbv4_open(rhs.get_pbv4_open());
      set_sol5_open(rhs.get_sol5_open());
      set_sol6_open(rhs.get_sol6_open());
      set_sol7_open(rhs.get_sol7_open());
      set_sol8a_open(rhs.get_sol8a_open());
      set_sol8b_open(rhs.get_sol8b_open());
      return *this;
    }

    static constexpr char const* AC1_OPEN_NAME = "ac1_open";
    inline void clear_ac1_open() { ac1_open_.clear(); }
    inline void set_ac1_open(const bool& value) { ac1_open_ = value; }
    inline void set_ac1_open(const bool&& value) { ac1_open_ = value; }
    inline bool& mutable_ac1_open() { return ac1_open_.get(); }
    inline const bool& get_ac1_open() const { return ac1_open_.get(); }
    inline bool ac1_open() const { return ac1_open_.get(); }

    static constexpr char const* AC2_OPEN_NAME = "ac2_open";
    inline void clear_ac2_open() { ac2_open_.clear(); }
    inline void set_ac2_open(const bool& value) { ac2_open_ = value; }
    inline void set_ac2_open(const bool&& value) { ac2_open_ = value; }
    inline bool& mutable_ac2_open() { return ac2_open_.get(); }
    inline const bool& get_ac2_open() const { return ac2_open_.get(); }
    inline bool ac2_open() const { return ac2_open_.get(); }

    static constexpr char const* PBV1_OPEN_NAME = "pbv1_open";
    inline void clear_pbv1_open() { pbv1_open_.clear(); }
    inline void set_pbv1_open(const bool& value) { pbv1_open_ = value; }
    inline void set_pbv1_open(const bool&& value) { pbv1_open_ = value; }
    inline bool& mutable_pbv1_open() { return pbv1_open_.get(); }
    inline const bool& get_pbv1_open() const { return pbv1_open_.get(); }
    inline bool pbv1_open() const { return pbv1_open_.get(); }

    static constexpr char const* PBV2_OPEN_NAME = "pbv2_open";
    inline void clear_pbv2_open() { pbv2_open_.clear(); }
    inline void set_pbv2_open(const bool& value) { pbv2_open_ = value; }
    inline void set_pbv2_open(const bool&& value) { pbv2_open_ = value; }
    inline bool& mutable_pbv2_open() { return pbv2_open_.get(); }
    inline const bool& get_pbv2_open() const { return pbv2_open_.get(); }
    inline bool pbv2_open() const { return pbv2_open_.get(); }

    static constexpr char const* PBV3_OPEN_NAME = "pbv3_open";
    inline void clear_pbv3_open() { pbv3_open_.clear(); }
    inline void set_pbv3_open(const bool& value) { pbv3_open_ = value; }
    inline void set_pbv3_open(const bool&& value) { pbv3_open_ = value; }
    inline bool& mutable_pbv3_open() { return pbv3_open_.get(); }
    inline const bool& get_pbv3_open() const { return pbv3_open_.get(); }
    inline bool pbv3_open() const { return pbv3_open_.get(); }

    static constexpr char const* PBV4_OPEN_NAME = "pbv4_open";
    inline void clear_pbv4_open() { pbv4_open_.clear(); }
    inline void set_pbv4_open(const bool& value) { pbv4_open_ = value; }
    inline void set_pbv4_open(const bool&& value) { pbv4_open_ = value; }
    inline bool& mutable_pbv4_open() { return pbv4_open_.get(); }
    inline const bool& get_pbv4_open() const { return pbv4_open_.get(); }
    inline bool pbv4_open() const { return pbv4_open_.get(); }

    static constexpr char const* SOL5_OPEN_NAME = "sol5_open";
    inline void clear_sol5_open() { sol5_open_.clear(); }
    inline void set_sol5_open(const bool& value) { sol5_open_ = value; }
    inline void set_sol5_open(const bool&& value) { sol5_open_ = value; }
    inline bool& mutable_sol5_open() { return sol5_open_.get(); }
    inline const bool& get_sol5_open() const { return sol5_open_.get(); }
    inline bool sol5_open() const { return sol5_open_.get(); }

    static constexpr char const* SOL6_OPEN_NAME = "sol6_open";
    inline void clear_sol6_open() { sol6_open_.clear(); }
    inline void set_sol6_open(const bool& value) { sol6_open_ = value; }
    inline void set_sol6_open(const bool&& value) { sol6_open_ = value; }
    inline bool& mutable_sol6_open() { return sol6_open_.get(); }
    inline const bool& get_sol6_open() const { return sol6_open_.get(); }
    inline bool sol6_open() const { return sol6_open_.get(); }

    static constexpr char const* SOL7_OPEN_NAME = "sol7_open";
    inline void clear_sol7_open() { sol7_open_.clear(); }
    inline void set_sol7_open(const bool& value) { sol7_open_ = value; }
    inline void set_sol7_open(const bool&& value) { sol7_open_ = value; }
    inline bool& mutable_sol7_open() { return sol7_open_.get(); }
    inline const bool& get_sol7_open() const { return sol7_open_.get(); }
    inline bool sol7_open() const { return sol7_open_.get(); }

    static constexpr char const* SOL8A_OPEN_NAME = "sol8a_open";
    inline void clear_sol8a_open() { sol8a_open_.clear(); }
    inline void set_sol8a_open(const bool& value) { sol8a_open_ = value; }
    inline void set_sol8a_open(const bool&& value) { sol8a_open_ = value; }
    inline bool& mutable_sol8a_open() { return sol8a_open_.get(); }
    inline const bool& get_sol8a_open() const { return sol8a_open_.get(); }
    inline bool sol8a_open() const { return sol8a_open_.get(); }

    static constexpr char const* SOL8B_OPEN_NAME = "sol8b_open";
    inline void clear_sol8b_open() { sol8b_open_.clear(); }
    inline void set_sol8b_open(const bool& value) { sol8b_open_ = value; }
    inline void set_sol8b_open(const bool&& value) { sol8b_open_ = value; }
    inline bool& mutable_sol8b_open() { return sol8b_open_.get(); }
    inline const bool& get_sol8b_open() const { return sol8b_open_.get(); }
    inline bool sol8b_open() const { return sol8b_open_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((false != ac1_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = ac1_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::AC1_OPEN), buffer, false);
      }

      if((false != ac2_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = ac2_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::AC2_OPEN), buffer, false);
      }

      if((false != pbv1_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pbv1_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBV1_OPEN), buffer, false);
      }

      if((false != pbv2_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pbv2_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBV2_OPEN), buffer, false);
      }

      if((false != pbv3_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pbv3_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBV3_OPEN), buffer, false);
      }

      if((false != pbv4_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pbv4_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBV4_OPEN), buffer, false);
      }

      if((false != sol5_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sol5_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOL5_OPEN), buffer, false);
      }

      if((false != sol6_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sol6_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOL6_OPEN), buffer, false);
      }

      if((false != sol7_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sol7_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOL7_OPEN), buffer, false);
      }

      if((false != sol8a_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sol8a_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOL8A_OPEN), buffer, false);
      }

      if((false != sol8b_open_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sol8b_open_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOL8B_OPEN), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::AC1_OPEN:
            return_value = ac1_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::AC2_OPEN:
            return_value = ac2_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PBV1_OPEN:
            return_value = pbv1_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PBV2_OPEN:
            return_value = pbv2_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PBV3_OPEN:
            return_value = pbv3_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PBV4_OPEN:
            return_value = pbv4_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOL5_OPEN:
            return_value = sol5_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOL6_OPEN:
            return_value = sol6_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOL7_OPEN:
            return_value = sol7_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOL8A_OPEN:
            return_value = sol8a_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOL8B_OPEN:
            return_value = sol8b_open_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_ac1_open();
      clear_ac2_open();
      clear_pbv1_open();
      clear_pbv2_open();
      clear_pbv3_open();
      clear_pbv4_open();
      clear_sol5_open();
      clear_sol6_open();
      clear_sol7_open();
      clear_sol8a_open();
      clear_sol8b_open();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::AC1_OPEN:
          name = AC1_OPEN_NAME;
          break;
        case FieldNumber::AC2_OPEN:
          name = AC2_OPEN_NAME;
          break;
        case FieldNumber::PBV1_OPEN:
          name = PBV1_OPEN_NAME;
          break;
        case FieldNumber::PBV2_OPEN:
          name = PBV2_OPEN_NAME;
          break;
        case FieldNumber::PBV3_OPEN:
          name = PBV3_OPEN_NAME;
          break;
        case FieldNumber::PBV4_OPEN:
          name = PBV4_OPEN_NAME;
          break;
        case FieldNumber::SOL5_OPEN:
          name = SOL5_OPEN_NAME;
          break;
        case FieldNumber::SOL6_OPEN:
          name = SOL6_OPEN_NAME;
          break;
        case FieldNumber::SOL7_OPEN:
          name = SOL7_OPEN_NAME;
          break;
        case FieldNumber::SOL8A_OPEN:
          name = SOL8A_OPEN_NAME;
          break;
        case FieldNumber::SOL8B_OPEN:
          name = SOL8B_OPEN_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = ac1_open_.to_string(left_chars, indent_level + 2, AC1_OPEN_NAME, true);
      left_chars = ac2_open_.to_string(left_chars, indent_level + 2, AC2_OPEN_NAME, false);
      left_chars = pbv1_open_.to_string(left_chars, indent_level + 2, PBV1_OPEN_NAME, false);
      left_chars = pbv2_open_.to_string(left_chars, indent_level + 2, PBV2_OPEN_NAME, false);
      left_chars = pbv3_open_.to_string(left_chars, indent_level + 2, PBV3_OPEN_NAME, false);
      left_chars = pbv4_open_.to_string(left_chars, indent_level + 2, PBV4_OPEN_NAME, false);
      left_chars = sol5_open_.to_string(left_chars, indent_level + 2, SOL5_OPEN_NAME, false);
      left_chars = sol6_open_.to_string(left_chars, indent_level + 2, SOL6_OPEN_NAME, false);
      left_chars = sol7_open_.to_string(left_chars, indent_level + 2, SOL7_OPEN_NAME, false);
      left_chars = sol8a_open_.to_string(left_chars, indent_level + 2, SOL8A_OPEN_NAME, false);
      left_chars = sol8b_open_.to_string(left_chars, indent_level + 2, SOL8B_OPEN_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::boolean ac1_open_ = false;
      EmbeddedProto::boolean ac2_open_ = false;
      EmbeddedProto::boolean pbv1_open_ = false;
      EmbeddedProto::boolean pbv2_open_ = false;
      EmbeddedProto::boolean pbv3_open_ = false;
      EmbeddedProto::boolean pbv4_open_ = false;
      EmbeddedProto::boolean sol5_open_ = false;
      EmbeddedProto::boolean sol6_open_ = false;
      EmbeddedProto::boolean sol7_open_ = false;
      EmbeddedProto::boolean sol8a_open_ = false;
      EmbeddedProto::boolean sol8b_open_ = false;

};

class SobTemperature final: public ::EmbeddedProto::MessageInterface
{
  public:
    SobTemperature() = default;
    SobTemperature(const SobTemperature& rhs )
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
    }

    SobTemperature(const SobTemperature&& rhs ) noexcept
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
    }

    ~SobTemperature() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TC1_TEMPERATURE = 1,
      TC2_TEMPERATURE = 2
    };

    SobTemperature& operator=(const SobTemperature& rhs)
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
      return *this;
    }

    SobTemperature& operator=(const SobTemperature&& rhs) noexcept
    {
      set_tc1_temperature(rhs.get_tc1_temperature());
      set_tc2_temperature(rhs.get_tc2_temperature());
      return *this;
    }

    static constexpr char const* TC1_TEMPERATURE_NAME = "tc1_temperature";
    inline void clear_tc1_temperature() { tc1_temperature_.clear(); }
    inline void set_tc1_temperature(const int32_t& value) { tc1_temperature_ = value; }
    inline void set_tc1_temperature(const int32_t&& value) { tc1_temperature_ = value; }
    inline int32_t& mutable_tc1_temperature() { return tc1_temperature_.get(); }
    inline const int32_t& get_tc1_temperature() const { return tc1_temperature_.get(); }
    inline int32_t tc1_temperature() const { return tc1_temperature_.get(); }

    static constexpr char const* TC2_TEMPERATURE_NAME = "tc2_temperature";
    inline void clear_tc2_temperature() { tc2_temperature_.clear(); }
    inline void set_tc2_temperature(const int32_t& value) { tc2_temperature_ = value; }
    inline void set_tc2_temperature(const int32_t&& value) { tc2_temperature_ = value; }
    inline int32_t& mutable_tc2_temperature() { return tc2_temperature_.get(); }
    inline const int32_t& get_tc2_temperature() const { return tc2_temperature_.get(); }
    inline int32_t tc2_temperature() const { return tc2_temperature_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != tc1_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = tc1_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TC1_TEMPERATURE), buffer, false);
      }

      if((0 != tc2_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = tc2_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TC2_TEMPERATURE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TC1_TEMPERATURE:
            return_value = tc1_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TC2_TEMPERATURE:
            return_value = tc2_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_tc1_temperature();
      clear_tc2_temperature();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TC1_TEMPERATURE:
          name = TC1_TEMPERATURE_NAME;
          break;
        case FieldNumber::TC2_TEMPERATURE:
          name = TC2_TEMPERATURE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = tc1_temperature_.to_string(left_chars, indent_level + 2, TC1_TEMPERATURE_NAME, true);
      left_chars = tc2_temperature_.to_string(left_chars, indent_level + 2, TC2_TEMPERATURE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 tc1_temperature_ = 0;
      EmbeddedProto::int32 tc2_temperature_ = 0;

};

class Gps final: public ::EmbeddedProto::MessageInterface
{
  public:
    Gps() = default;
    Gps(const Gps& rhs )
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_antenna_altitude(rhs.get_antenna_altitude());
      set_geo_id_altitude(rhs.get_geo_id_altitude());
      set_total_altitude(rhs.get_total_altitude());
      set_time(rhs.get_time());
    }

    Gps(const Gps&& rhs ) noexcept
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_antenna_altitude(rhs.get_antenna_altitude());
      set_geo_id_altitude(rhs.get_geo_id_altitude());
      set_total_altitude(rhs.get_total_altitude());
      set_time(rhs.get_time());
    }

    ~Gps() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      LATITUDE = 1,
      LONGITUDE = 2,
      ANTENNA_ALTITUDE = 3,
      GEO_ID_ALTITUDE = 4,
      TOTAL_ALTITUDE = 5,
      TIME = 6
    };

    Gps& operator=(const Gps& rhs)
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_antenna_altitude(rhs.get_antenna_altitude());
      set_geo_id_altitude(rhs.get_geo_id_altitude());
      set_total_altitude(rhs.get_total_altitude());
      set_time(rhs.get_time());
      return *this;
    }

    Gps& operator=(const Gps&& rhs) noexcept
    {
      set_latitude(rhs.get_latitude());
      set_longitude(rhs.get_longitude());
      set_antenna_altitude(rhs.get_antenna_altitude());
      set_geo_id_altitude(rhs.get_geo_id_altitude());
      set_total_altitude(rhs.get_total_altitude());
      set_time(rhs.get_time());
      return *this;
    }

    static constexpr char const* LATITUDE_NAME = "latitude";
    inline void clear_latitude() { latitude_.clear(); }
    inline void set_latitude(const CoordinateType& value) { latitude_ = value; }
    inline void set_latitude(const CoordinateType&& value) { latitude_ = value; }
    inline CoordinateType& mutable_latitude() { return latitude_; }
    inline const CoordinateType& get_latitude() const { return latitude_; }
    inline const CoordinateType& latitude() const { return latitude_; }

    static constexpr char const* LONGITUDE_NAME = "longitude";
    inline void clear_longitude() { longitude_.clear(); }
    inline void set_longitude(const CoordinateType& value) { longitude_ = value; }
    inline void set_longitude(const CoordinateType&& value) { longitude_ = value; }
    inline CoordinateType& mutable_longitude() { return longitude_; }
    inline const CoordinateType& get_longitude() const { return longitude_; }
    inline const CoordinateType& longitude() const { return longitude_; }

    static constexpr char const* ANTENNA_ALTITUDE_NAME = "antenna_altitude";
    inline void clear_antenna_altitude() { antenna_altitude_.clear(); }
    inline void set_antenna_altitude(const AltitudeType& value) { antenna_altitude_ = value; }
    inline void set_antenna_altitude(const AltitudeType&& value) { antenna_altitude_ = value; }
    inline AltitudeType& mutable_antenna_altitude() { return antenna_altitude_; }
    inline const AltitudeType& get_antenna_altitude() const { return antenna_altitude_; }
    inline const AltitudeType& antenna_altitude() const { return antenna_altitude_; }

    static constexpr char const* GEO_ID_ALTITUDE_NAME = "geo_id_altitude";
    inline void clear_geo_id_altitude() { geo_id_altitude_.clear(); }
    inline void set_geo_id_altitude(const AltitudeType& value) { geo_id_altitude_ = value; }
    inline void set_geo_id_altitude(const AltitudeType&& value) { geo_id_altitude_ = value; }
    inline AltitudeType& mutable_geo_id_altitude() { return geo_id_altitude_; }
    inline const AltitudeType& get_geo_id_altitude() const { return geo_id_altitude_; }
    inline const AltitudeType& geo_id_altitude() const { return geo_id_altitude_; }

    static constexpr char const* TOTAL_ALTITUDE_NAME = "total_altitude";
    inline void clear_total_altitude() { total_altitude_.clear(); }
    inline void set_total_altitude(const AltitudeType& value) { total_altitude_ = value; }
    inline void set_total_altitude(const AltitudeType&& value) { total_altitude_ = value; }
    inline AltitudeType& mutable_total_altitude() { return total_altitude_; }
    inline const AltitudeType& get_total_altitude() const { return total_altitude_; }
    inline const AltitudeType& total_altitude() const { return total_altitude_; }

    static constexpr char const* TIME_NAME = "time";
    inline void clear_time() { time_.clear(); }
    inline void set_time(const uint32_t& value) { time_ = value; }
    inline void set_time(const uint32_t&& value) { time_ = value; }
    inline uint32_t& mutable_time() { return time_.get(); }
    inline const uint32_t& get_time() const { return time_.get(); }
    inline uint32_t time() const { return time_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = latitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LATITUDE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = longitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LONGITUDE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = antenna_altitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ANTENNA_ALTITUDE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = geo_id_altitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GEO_ID_ALTITUDE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = total_altitude_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TOTAL_ALTITUDE), buffer, false);
      }

      if((0U != time_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = time_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIME), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::LATITUDE:
            return_value = latitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LONGITUDE:
            return_value = longitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::ANTENNA_ALTITUDE:
            return_value = antenna_altitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GEO_ID_ALTITUDE:
            return_value = geo_id_altitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TOTAL_ALTITUDE:
            return_value = total_altitude_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TIME:
            return_value = time_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_latitude();
      clear_longitude();
      clear_antenna_altitude();
      clear_geo_id_altitude();
      clear_total_altitude();
      clear_time();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::LATITUDE:
          name = LATITUDE_NAME;
          break;
        case FieldNumber::LONGITUDE:
          name = LONGITUDE_NAME;
          break;
        case FieldNumber::ANTENNA_ALTITUDE:
          name = ANTENNA_ALTITUDE_NAME;
          break;
        case FieldNumber::GEO_ID_ALTITUDE:
          name = GEO_ID_ALTITUDE_NAME;
          break;
        case FieldNumber::TOTAL_ALTITUDE:
          name = TOTAL_ALTITUDE_NAME;
          break;
        case FieldNumber::TIME:
          name = TIME_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = latitude_.to_string(left_chars, indent_level + 2, LATITUDE_NAME, true);
      left_chars = longitude_.to_string(left_chars, indent_level + 2, LONGITUDE_NAME, false);
      left_chars = antenna_altitude_.to_string(left_chars, indent_level + 2, ANTENNA_ALTITUDE_NAME, false);
      left_chars = geo_id_altitude_.to_string(left_chars, indent_level + 2, GEO_ID_ALTITUDE_NAME, false);
      left_chars = total_altitude_.to_string(left_chars, indent_level + 2, TOTAL_ALTITUDE_NAME, false);
      left_chars = time_.to_string(left_chars, indent_level + 2, TIME_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      CoordinateType latitude_;
      CoordinateType longitude_;
      AltitudeType antenna_altitude_;
      AltitudeType geo_id_altitude_;
      AltitudeType total_altitude_;
      EmbeddedProto::uint32 time_ = 0U;

};

class TelemetryMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    TelemetryMessage() = default;
    TelemetryMessage(const TelemetryMessage& rhs )
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::GPS:
          set_gps(rhs.get_gps());
          break;

        case FieldNumber::BARO:
          set_baro(rhs.get_baro());
          break;

        case FieldNumber::IMU:
          set_imu(rhs.get_imu());
          break;

        case FieldNumber::BATTERY:
          set_battery(rhs.get_battery());
          break;

        case FieldNumber::FLASHSTATE:
          set_flashState(rhs.get_flashState());
          break;

        case FieldNumber::DMBPRESSURE:
          set_dmbPressure(rhs.get_dmbPressure());
          break;

        case FieldNumber::PBBPRESSURE:
          set_pbbPressure(rhs.get_pbbPressure());
          break;

        case FieldNumber::PBBTEMPERATURE:
          set_pbbTemperature(rhs.get_pbbTemperature());
          break;

        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          set_combustionControlStatus(rhs.get_combustionControlStatus());
          break;

        case FieldNumber::RCUPRESSURE:
          set_rcuPressure(rhs.get_rcuPressure());
          break;

        case FieldNumber::RCUTEMPERATURE:
          set_rcuTemperature(rhs.get_rcuTemperature());
          break;

        case FieldNumber::NOSLOADCELL:
          set_nosLoadCell(rhs.get_nosLoadCell());
          break;

        case FieldNumber::RELAYSTATUS:
          set_relayStatus(rhs.get_relayStatus());
          break;

        case FieldNumber::PADBOXSTATUS:
          set_padBoxStatus(rhs.get_padBoxStatus());
          break;

        case FieldNumber::LAUNCHRAILLOADCELL:
          set_launchRailLoadCell(rhs.get_launchRailLoadCell());
          break;

        case FieldNumber::SOBTEMPERATURE:
          set_sobTemperature(rhs.get_sobTemperature());
          break;

        case FieldNumber::PRESSURELOG:
          set_pressureLog(rhs.get_pressureLog());
          break;

        default:
          break;
      }

    }

    TelemetryMessage(const TelemetryMessage&& rhs ) noexcept
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::GPS:
          set_gps(rhs.get_gps());
          break;

        case FieldNumber::BARO:
          set_baro(rhs.get_baro());
          break;

        case FieldNumber::IMU:
          set_imu(rhs.get_imu());
          break;

        case FieldNumber::BATTERY:
          set_battery(rhs.get_battery());
          break;

        case FieldNumber::FLASHSTATE:
          set_flashState(rhs.get_flashState());
          break;

        case FieldNumber::DMBPRESSURE:
          set_dmbPressure(rhs.get_dmbPressure());
          break;

        case FieldNumber::PBBPRESSURE:
          set_pbbPressure(rhs.get_pbbPressure());
          break;

        case FieldNumber::PBBTEMPERATURE:
          set_pbbTemperature(rhs.get_pbbTemperature());
          break;

        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          set_combustionControlStatus(rhs.get_combustionControlStatus());
          break;

        case FieldNumber::RCUPRESSURE:
          set_rcuPressure(rhs.get_rcuPressure());
          break;

        case FieldNumber::RCUTEMPERATURE:
          set_rcuTemperature(rhs.get_rcuTemperature());
          break;

        case FieldNumber::NOSLOADCELL:
          set_nosLoadCell(rhs.get_nosLoadCell());
          break;

        case FieldNumber::RELAYSTATUS:
          set_relayStatus(rhs.get_relayStatus());
          break;

        case FieldNumber::PADBOXSTATUS:
          set_padBoxStatus(rhs.get_padBoxStatus());
          break;

        case FieldNumber::LAUNCHRAILLOADCELL:
          set_launchRailLoadCell(rhs.get_launchRailLoadCell());
          break;

        case FieldNumber::SOBTEMPERATURE:
          set_sobTemperature(rhs.get_sobTemperature());
          break;

        case FieldNumber::PRESSURELOG:
          set_pressureLog(rhs.get_pressureLog());
          break;

        default:
          break;
      }

    }

    ~TelemetryMessage() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SOURCE = 1,
      TARGET = 2,
      GPS = 3,
      BARO = 4,
      IMU = 5,
      BATTERY = 6,
      FLASHSTATE = 7,
      DMBPRESSURE = 8,
      PBBPRESSURE = 9,
      PBBTEMPERATURE = 10,
      COMBUSTIONCONTROLSTATUS = 11,
      RCUPRESSURE = 12,
      RCUTEMPERATURE = 13,
      NOSLOADCELL = 14,
      RELAYSTATUS = 15,
      PADBOXSTATUS = 16,
      LAUNCHRAILLOADCELL = 17,
      SOBTEMPERATURE = 18,
      PRESSURELOG = 19
    };

    TelemetryMessage& operator=(const TelemetryMessage& rhs)
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::GPS:
          set_gps(rhs.get_gps());
          break;

        case FieldNumber::BARO:
          set_baro(rhs.get_baro());
          break;

        case FieldNumber::IMU:
          set_imu(rhs.get_imu());
          break;

        case FieldNumber::BATTERY:
          set_battery(rhs.get_battery());
          break;

        case FieldNumber::FLASHSTATE:
          set_flashState(rhs.get_flashState());
          break;

        case FieldNumber::DMBPRESSURE:
          set_dmbPressure(rhs.get_dmbPressure());
          break;

        case FieldNumber::PBBPRESSURE:
          set_pbbPressure(rhs.get_pbbPressure());
          break;

        case FieldNumber::PBBTEMPERATURE:
          set_pbbTemperature(rhs.get_pbbTemperature());
          break;

        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          set_combustionControlStatus(rhs.get_combustionControlStatus());
          break;

        case FieldNumber::RCUPRESSURE:
          set_rcuPressure(rhs.get_rcuPressure());
          break;

        case FieldNumber::RCUTEMPERATURE:
          set_rcuTemperature(rhs.get_rcuTemperature());
          break;

        case FieldNumber::NOSLOADCELL:
          set_nosLoadCell(rhs.get_nosLoadCell());
          break;

        case FieldNumber::RELAYSTATUS:
          set_relayStatus(rhs.get_relayStatus());
          break;

        case FieldNumber::PADBOXSTATUS:
          set_padBoxStatus(rhs.get_padBoxStatus());
          break;

        case FieldNumber::LAUNCHRAILLOADCELL:
          set_launchRailLoadCell(rhs.get_launchRailLoadCell());
          break;

        case FieldNumber::SOBTEMPERATURE:
          set_sobTemperature(rhs.get_sobTemperature());
          break;

        case FieldNumber::PRESSURELOG:
          set_pressureLog(rhs.get_pressureLog());
          break;

        default:
          break;
      }

      return *this;
    }

    TelemetryMessage& operator=(const TelemetryMessage&& rhs) noexcept
    {
      set_source(rhs.get_source());
      set_target(rhs.get_target());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::GPS:
          set_gps(rhs.get_gps());
          break;

        case FieldNumber::BARO:
          set_baro(rhs.get_baro());
          break;

        case FieldNumber::IMU:
          set_imu(rhs.get_imu());
          break;

        case FieldNumber::BATTERY:
          set_battery(rhs.get_battery());
          break;

        case FieldNumber::FLASHSTATE:
          set_flashState(rhs.get_flashState());
          break;

        case FieldNumber::DMBPRESSURE:
          set_dmbPressure(rhs.get_dmbPressure());
          break;

        case FieldNumber::PBBPRESSURE:
          set_pbbPressure(rhs.get_pbbPressure());
          break;

        case FieldNumber::PBBTEMPERATURE:
          set_pbbTemperature(rhs.get_pbbTemperature());
          break;

        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          set_combustionControlStatus(rhs.get_combustionControlStatus());
          break;

        case FieldNumber::RCUPRESSURE:
          set_rcuPressure(rhs.get_rcuPressure());
          break;

        case FieldNumber::RCUTEMPERATURE:
          set_rcuTemperature(rhs.get_rcuTemperature());
          break;

        case FieldNumber::NOSLOADCELL:
          set_nosLoadCell(rhs.get_nosLoadCell());
          break;

        case FieldNumber::RELAYSTATUS:
          set_relayStatus(rhs.get_relayStatus());
          break;

        case FieldNumber::PADBOXSTATUS:
          set_padBoxStatus(rhs.get_padBoxStatus());
          break;

        case FieldNumber::LAUNCHRAILLOADCELL:
          set_launchRailLoadCell(rhs.get_launchRailLoadCell());
          break;

        case FieldNumber::SOBTEMPERATURE:
          set_sobTemperature(rhs.get_sobTemperature());
          break;

        case FieldNumber::PRESSURELOG:
          set_pressureLog(rhs.get_pressureLog());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* SOURCE_NAME = "source";
    inline void clear_source() { source_.clear(); }
    inline void set_source(const Node& value) { source_ = value; }
    inline void set_source(const Node&& value) { source_ = value; }
    inline const Node& get_source() const { return source_.get(); }
    inline Node source() const { return source_.get(); }

    static constexpr char const* TARGET_NAME = "target";
    inline void clear_target() { target_.clear(); }
    inline void set_target(const Node& value) { target_ = value; }
    inline void set_target(const Node&& value) { target_ = value; }
    inline const Node& get_target() const { return target_.get(); }
    inline Node target() const { return target_.get(); }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* GPS_NAME = "gps";
    inline bool has_gps() const
    {
      return FieldNumber::GPS == which_message_;
    }
    inline void clear_gps()
    {
      if(FieldNumber::GPS == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.gps_.~Gps();
      }
    }
    inline void set_gps(const Gps& value)
    {
      if(FieldNumber::GPS != which_message_)
      {
        init_message(FieldNumber::GPS);
      }
      message_.gps_ = value;
    }
    inline void set_gps(const Gps&& value)
    {
      if(FieldNumber::GPS != which_message_)
      {
        init_message(FieldNumber::GPS);
      }
      message_.gps_ = value;
    }
    inline Gps& mutable_gps()
    {
      if(FieldNumber::GPS != which_message_)
      {
        init_message(FieldNumber::GPS);
      }
      return message_.gps_;
    }
    inline const Gps& get_gps() const { return message_.gps_; }
    inline const Gps& gps() const { return message_.gps_; }

    static constexpr char const* BARO_NAME = "baro";
    inline bool has_baro() const
    {
      return FieldNumber::BARO == which_message_;
    }
    inline void clear_baro()
    {
      if(FieldNumber::BARO == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.baro_.~Baro();
      }
    }
    inline void set_baro(const Baro& value)
    {
      if(FieldNumber::BARO != which_message_)
      {
        init_message(FieldNumber::BARO);
      }
      message_.baro_ = value;
    }
    inline void set_baro(const Baro&& value)
    {
      if(FieldNumber::BARO != which_message_)
      {
        init_message(FieldNumber::BARO);
      }
      message_.baro_ = value;
    }
    inline Baro& mutable_baro()
    {
      if(FieldNumber::BARO != which_message_)
      {
        init_message(FieldNumber::BARO);
      }
      return message_.baro_;
    }
    inline const Baro& get_baro() const { return message_.baro_; }
    inline const Baro& baro() const { return message_.baro_; }

    static constexpr char const* IMU_NAME = "imu";
    inline bool has_imu() const
    {
      return FieldNumber::IMU == which_message_;
    }
    inline void clear_imu()
    {
      if(FieldNumber::IMU == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.imu_.~Imu();
      }
    }
    inline void set_imu(const Imu& value)
    {
      if(FieldNumber::IMU != which_message_)
      {
        init_message(FieldNumber::IMU);
      }
      message_.imu_ = value;
    }
    inline void set_imu(const Imu&& value)
    {
      if(FieldNumber::IMU != which_message_)
      {
        init_message(FieldNumber::IMU);
      }
      message_.imu_ = value;
    }
    inline Imu& mutable_imu()
    {
      if(FieldNumber::IMU != which_message_)
      {
        init_message(FieldNumber::IMU);
      }
      return message_.imu_;
    }
    inline const Imu& get_imu() const { return message_.imu_; }
    inline const Imu& imu() const { return message_.imu_; }

    static constexpr char const* BATTERY_NAME = "battery";
    inline bool has_battery() const
    {
      return FieldNumber::BATTERY == which_message_;
    }
    inline void clear_battery()
    {
      if(FieldNumber::BATTERY == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.battery_.~Battery();
      }
    }
    inline void set_battery(const Battery& value)
    {
      if(FieldNumber::BATTERY != which_message_)
      {
        init_message(FieldNumber::BATTERY);
      }
      message_.battery_ = value;
    }
    inline void set_battery(const Battery&& value)
    {
      if(FieldNumber::BATTERY != which_message_)
      {
        init_message(FieldNumber::BATTERY);
      }
      message_.battery_ = value;
    }
    inline Battery& mutable_battery()
    {
      if(FieldNumber::BATTERY != which_message_)
      {
        init_message(FieldNumber::BATTERY);
      }
      return message_.battery_;
    }
    inline const Battery& get_battery() const { return message_.battery_; }
    inline const Battery& battery() const { return message_.battery_; }

    static constexpr char const* FLASHSTATE_NAME = "flashState";
    inline bool has_flashState() const
    {
      return FieldNumber::FLASHSTATE == which_message_;
    }
    inline void clear_flashState()
    {
      if(FieldNumber::FLASHSTATE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.flashState_.~Flash();
      }
    }
    inline void set_flashState(const Flash& value)
    {
      if(FieldNumber::FLASHSTATE != which_message_)
      {
        init_message(FieldNumber::FLASHSTATE);
      }
      message_.flashState_ = value;
    }
    inline void set_flashState(const Flash&& value)
    {
      if(FieldNumber::FLASHSTATE != which_message_)
      {
        init_message(FieldNumber::FLASHSTATE);
      }
      message_.flashState_ = value;
    }
    inline Flash& mutable_flashState()
    {
      if(FieldNumber::FLASHSTATE != which_message_)
      {
        init_message(FieldNumber::FLASHSTATE);
      }
      return message_.flashState_;
    }
    inline const Flash& get_flashState() const { return message_.flashState_; }
    inline const Flash& flashState() const { return message_.flashState_; }

    static constexpr char const* DMBPRESSURE_NAME = "dmbPressure";
    inline bool has_dmbPressure() const
    {
      return FieldNumber::DMBPRESSURE == which_message_;
    }
    inline void clear_dmbPressure()
    {
      if(FieldNumber::DMBPRESSURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.dmbPressure_.~DmbPressure();
      }
    }
    inline void set_dmbPressure(const DmbPressure& value)
    {
      if(FieldNumber::DMBPRESSURE != which_message_)
      {
        init_message(FieldNumber::DMBPRESSURE);
      }
      message_.dmbPressure_ = value;
    }
    inline void set_dmbPressure(const DmbPressure&& value)
    {
      if(FieldNumber::DMBPRESSURE != which_message_)
      {
        init_message(FieldNumber::DMBPRESSURE);
      }
      message_.dmbPressure_ = value;
    }
    inline DmbPressure& mutable_dmbPressure()
    {
      if(FieldNumber::DMBPRESSURE != which_message_)
      {
        init_message(FieldNumber::DMBPRESSURE);
      }
      return message_.dmbPressure_;
    }
    inline const DmbPressure& get_dmbPressure() const { return message_.dmbPressure_; }
    inline const DmbPressure& dmbPressure() const { return message_.dmbPressure_; }

    static constexpr char const* PBBPRESSURE_NAME = "pbbPressure";
    inline bool has_pbbPressure() const
    {
      return FieldNumber::PBBPRESSURE == which_message_;
    }
    inline void clear_pbbPressure()
    {
      if(FieldNumber::PBBPRESSURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.pbbPressure_.~PbbPressure();
      }
    }
    inline void set_pbbPressure(const PbbPressure& value)
    {
      if(FieldNumber::PBBPRESSURE != which_message_)
      {
        init_message(FieldNumber::PBBPRESSURE);
      }
      message_.pbbPressure_ = value;
    }
    inline void set_pbbPressure(const PbbPressure&& value)
    {
      if(FieldNumber::PBBPRESSURE != which_message_)
      {
        init_message(FieldNumber::PBBPRESSURE);
      }
      message_.pbbPressure_ = value;
    }
    inline PbbPressure& mutable_pbbPressure()
    {
      if(FieldNumber::PBBPRESSURE != which_message_)
      {
        init_message(FieldNumber::PBBPRESSURE);
      }
      return message_.pbbPressure_;
    }
    inline const PbbPressure& get_pbbPressure() const { return message_.pbbPressure_; }
    inline const PbbPressure& pbbPressure() const { return message_.pbbPressure_; }

    static constexpr char const* PBBTEMPERATURE_NAME = "pbbTemperature";
    inline bool has_pbbTemperature() const
    {
      return FieldNumber::PBBTEMPERATURE == which_message_;
    }
    inline void clear_pbbTemperature()
    {
      if(FieldNumber::PBBTEMPERATURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.pbbTemperature_.~PbbTemperature();
      }
    }
    inline void set_pbbTemperature(const PbbTemperature& value)
    {
      if(FieldNumber::PBBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::PBBTEMPERATURE);
      }
      message_.pbbTemperature_ = value;
    }
    inline void set_pbbTemperature(const PbbTemperature&& value)
    {
      if(FieldNumber::PBBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::PBBTEMPERATURE);
      }
      message_.pbbTemperature_ = value;
    }
    inline PbbTemperature& mutable_pbbTemperature()
    {
      if(FieldNumber::PBBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::PBBTEMPERATURE);
      }
      return message_.pbbTemperature_;
    }
    inline const PbbTemperature& get_pbbTemperature() const { return message_.pbbTemperature_; }
    inline const PbbTemperature& pbbTemperature() const { return message_.pbbTemperature_; }

    static constexpr char const* COMBUSTIONCONTROLSTATUS_NAME = "combustionControlStatus";
    inline bool has_combustionControlStatus() const
    {
      return FieldNumber::COMBUSTIONCONTROLSTATUS == which_message_;
    }
    inline void clear_combustionControlStatus()
    {
      if(FieldNumber::COMBUSTIONCONTROLSTATUS == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.combustionControlStatus_.~CombustionControlStatus();
      }
    }
    inline void set_combustionControlStatus(const CombustionControlStatus& value)
    {
      if(FieldNumber::COMBUSTIONCONTROLSTATUS != which_message_)
      {
        init_message(FieldNumber::COMBUSTIONCONTROLSTATUS);
      }
      message_.combustionControlStatus_ = value;
    }
    inline void set_combustionControlStatus(const CombustionControlStatus&& value)
    {
      if(FieldNumber::COMBUSTIONCONTROLSTATUS != which_message_)
      {
        init_message(FieldNumber::COMBUSTIONCONTROLSTATUS);
      }
      message_.combustionControlStatus_ = value;
    }
    inline CombustionControlStatus& mutable_combustionControlStatus()
    {
      if(FieldNumber::COMBUSTIONCONTROLSTATUS != which_message_)
      {
        init_message(FieldNumber::COMBUSTIONCONTROLSTATUS);
      }
      return message_.combustionControlStatus_;
    }
    inline const CombustionControlStatus& get_combustionControlStatus() const { return message_.combustionControlStatus_; }
    inline const CombustionControlStatus& combustionControlStatus() const { return message_.combustionControlStatus_; }

    static constexpr char const* RCUPRESSURE_NAME = "rcuPressure";
    inline bool has_rcuPressure() const
    {
      return FieldNumber::RCUPRESSURE == which_message_;
    }
    inline void clear_rcuPressure()
    {
      if(FieldNumber::RCUPRESSURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.rcuPressure_.~RcuPressure();
      }
    }
    inline void set_rcuPressure(const RcuPressure& value)
    {
      if(FieldNumber::RCUPRESSURE != which_message_)
      {
        init_message(FieldNumber::RCUPRESSURE);
      }
      message_.rcuPressure_ = value;
    }
    inline void set_rcuPressure(const RcuPressure&& value)
    {
      if(FieldNumber::RCUPRESSURE != which_message_)
      {
        init_message(FieldNumber::RCUPRESSURE);
      }
      message_.rcuPressure_ = value;
    }
    inline RcuPressure& mutable_rcuPressure()
    {
      if(FieldNumber::RCUPRESSURE != which_message_)
      {
        init_message(FieldNumber::RCUPRESSURE);
      }
      return message_.rcuPressure_;
    }
    inline const RcuPressure& get_rcuPressure() const { return message_.rcuPressure_; }
    inline const RcuPressure& rcuPressure() const { return message_.rcuPressure_; }

    static constexpr char const* RCUTEMPERATURE_NAME = "rcuTemperature";
    inline bool has_rcuTemperature() const
    {
      return FieldNumber::RCUTEMPERATURE == which_message_;
    }
    inline void clear_rcuTemperature()
    {
      if(FieldNumber::RCUTEMPERATURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.rcuTemperature_.~RcuTemperature();
      }
    }
    inline void set_rcuTemperature(const RcuTemperature& value)
    {
      if(FieldNumber::RCUTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::RCUTEMPERATURE);
      }
      message_.rcuTemperature_ = value;
    }
    inline void set_rcuTemperature(const RcuTemperature&& value)
    {
      if(FieldNumber::RCUTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::RCUTEMPERATURE);
      }
      message_.rcuTemperature_ = value;
    }
    inline RcuTemperature& mutable_rcuTemperature()
    {
      if(FieldNumber::RCUTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::RCUTEMPERATURE);
      }
      return message_.rcuTemperature_;
    }
    inline const RcuTemperature& get_rcuTemperature() const { return message_.rcuTemperature_; }
    inline const RcuTemperature& rcuTemperature() const { return message_.rcuTemperature_; }

    static constexpr char const* NOSLOADCELL_NAME = "nosLoadCell";
    inline bool has_nosLoadCell() const
    {
      return FieldNumber::NOSLOADCELL == which_message_;
    }
    inline void clear_nosLoadCell()
    {
      if(FieldNumber::NOSLOADCELL == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.nosLoadCell_.~NosLoadCell();
      }
    }
    inline void set_nosLoadCell(const NosLoadCell& value)
    {
      if(FieldNumber::NOSLOADCELL != which_message_)
      {
        init_message(FieldNumber::NOSLOADCELL);
      }
      message_.nosLoadCell_ = value;
    }
    inline void set_nosLoadCell(const NosLoadCell&& value)
    {
      if(FieldNumber::NOSLOADCELL != which_message_)
      {
        init_message(FieldNumber::NOSLOADCELL);
      }
      message_.nosLoadCell_ = value;
    }
    inline NosLoadCell& mutable_nosLoadCell()
    {
      if(FieldNumber::NOSLOADCELL != which_message_)
      {
        init_message(FieldNumber::NOSLOADCELL);
      }
      return message_.nosLoadCell_;
    }
    inline const NosLoadCell& get_nosLoadCell() const { return message_.nosLoadCell_; }
    inline const NosLoadCell& nosLoadCell() const { return message_.nosLoadCell_; }

    static constexpr char const* RELAYSTATUS_NAME = "relayStatus";
    inline bool has_relayStatus() const
    {
      return FieldNumber::RELAYSTATUS == which_message_;
    }
    inline void clear_relayStatus()
    {
      if(FieldNumber::RELAYSTATUS == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.relayStatus_.~RelayStatus();
      }
    }
    inline void set_relayStatus(const RelayStatus& value)
    {
      if(FieldNumber::RELAYSTATUS != which_message_)
      {
        init_message(FieldNumber::RELAYSTATUS);
      }
      message_.relayStatus_ = value;
    }
    inline void set_relayStatus(const RelayStatus&& value)
    {
      if(FieldNumber::RELAYSTATUS != which_message_)
      {
        init_message(FieldNumber::RELAYSTATUS);
      }
      message_.relayStatus_ = value;
    }
    inline RelayStatus& mutable_relayStatus()
    {
      if(FieldNumber::RELAYSTATUS != which_message_)
      {
        init_message(FieldNumber::RELAYSTATUS);
      }
      return message_.relayStatus_;
    }
    inline const RelayStatus& get_relayStatus() const { return message_.relayStatus_; }
    inline const RelayStatus& relayStatus() const { return message_.relayStatus_; }

    static constexpr char const* PADBOXSTATUS_NAME = "padBoxStatus";
    inline bool has_padBoxStatus() const
    {
      return FieldNumber::PADBOXSTATUS == which_message_;
    }
    inline void clear_padBoxStatus()
    {
      if(FieldNumber::PADBOXSTATUS == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.padBoxStatus_.~PadBoxStatus();
      }
    }
    inline void set_padBoxStatus(const PadBoxStatus& value)
    {
      if(FieldNumber::PADBOXSTATUS != which_message_)
      {
        init_message(FieldNumber::PADBOXSTATUS);
      }
      message_.padBoxStatus_ = value;
    }
    inline void set_padBoxStatus(const PadBoxStatus&& value)
    {
      if(FieldNumber::PADBOXSTATUS != which_message_)
      {
        init_message(FieldNumber::PADBOXSTATUS);
      }
      message_.padBoxStatus_ = value;
    }
    inline PadBoxStatus& mutable_padBoxStatus()
    {
      if(FieldNumber::PADBOXSTATUS != which_message_)
      {
        init_message(FieldNumber::PADBOXSTATUS);
      }
      return message_.padBoxStatus_;
    }
    inline const PadBoxStatus& get_padBoxStatus() const { return message_.padBoxStatus_; }
    inline const PadBoxStatus& padBoxStatus() const { return message_.padBoxStatus_; }

    static constexpr char const* LAUNCHRAILLOADCELL_NAME = "launchRailLoadCell";
    inline bool has_launchRailLoadCell() const
    {
      return FieldNumber::LAUNCHRAILLOADCELL == which_message_;
    }
    inline void clear_launchRailLoadCell()
    {
      if(FieldNumber::LAUNCHRAILLOADCELL == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.launchRailLoadCell_.~LaunchRailLoadCell();
      }
    }
    inline void set_launchRailLoadCell(const LaunchRailLoadCell& value)
    {
      if(FieldNumber::LAUNCHRAILLOADCELL != which_message_)
      {
        init_message(FieldNumber::LAUNCHRAILLOADCELL);
      }
      message_.launchRailLoadCell_ = value;
    }
    inline void set_launchRailLoadCell(const LaunchRailLoadCell&& value)
    {
      if(FieldNumber::LAUNCHRAILLOADCELL != which_message_)
      {
        init_message(FieldNumber::LAUNCHRAILLOADCELL);
      }
      message_.launchRailLoadCell_ = value;
    }
    inline LaunchRailLoadCell& mutable_launchRailLoadCell()
    {
      if(FieldNumber::LAUNCHRAILLOADCELL != which_message_)
      {
        init_message(FieldNumber::LAUNCHRAILLOADCELL);
      }
      return message_.launchRailLoadCell_;
    }
    inline const LaunchRailLoadCell& get_launchRailLoadCell() const { return message_.launchRailLoadCell_; }
    inline const LaunchRailLoadCell& launchRailLoadCell() const { return message_.launchRailLoadCell_; }

    static constexpr char const* SOBTEMPERATURE_NAME = "sobTemperature";
    inline bool has_sobTemperature() const
    {
      return FieldNumber::SOBTEMPERATURE == which_message_;
    }
    inline void clear_sobTemperature()
    {
      if(FieldNumber::SOBTEMPERATURE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.sobTemperature_.~SobTemperature();
      }
    }
    inline void set_sobTemperature(const SobTemperature& value)
    {
      if(FieldNumber::SOBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::SOBTEMPERATURE);
      }
      message_.sobTemperature_ = value;
    }
    inline void set_sobTemperature(const SobTemperature&& value)
    {
      if(FieldNumber::SOBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::SOBTEMPERATURE);
      }
      message_.sobTemperature_ = value;
    }
    inline SobTemperature& mutable_sobTemperature()
    {
      if(FieldNumber::SOBTEMPERATURE != which_message_)
      {
        init_message(FieldNumber::SOBTEMPERATURE);
      }
      return message_.sobTemperature_;
    }
    inline const SobTemperature& get_sobTemperature() const { return message_.sobTemperature_; }
    inline const SobTemperature& sobTemperature() const { return message_.sobTemperature_; }

    static constexpr char const* PRESSURELOG_NAME = "pressureLog";
    inline bool has_pressureLog() const
    {
      return FieldNumber::PRESSURELOG == which_message_;
    }
    inline void clear_pressureLog()
    {
      if(FieldNumber::PRESSURELOG == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.pressureLog_.~PressureLog();
      }
    }
    inline void set_pressureLog(const PressureLog& value)
    {
      if(FieldNumber::PRESSURELOG != which_message_)
      {
        init_message(FieldNumber::PRESSURELOG);
      }
      message_.pressureLog_ = value;
    }
    inline void set_pressureLog(const PressureLog&& value)
    {
      if(FieldNumber::PRESSURELOG != which_message_)
      {
        init_message(FieldNumber::PRESSURELOG);
      }
      message_.pressureLog_ = value;
    }
    inline PressureLog& mutable_pressureLog()
    {
      if(FieldNumber::PRESSURELOG != which_message_)
      {
        init_message(FieldNumber::PRESSURELOG);
      }
      return message_.pressureLog_;
    }
    inline const PressureLog& get_pressureLog() const { return message_.pressureLog_; }
    inline const PressureLog& pressureLog() const { return message_.pressureLog_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Node>(0) != source_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = source_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOURCE), buffer, false);
      }

      if((static_cast<Node>(0) != target_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = target_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TARGET), buffer, false);
      }

      switch(which_message_)
      {
        case FieldNumber::GPS:
          if(has_gps() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.gps_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GPS), buffer, true);
          }
          break;

        case FieldNumber::BARO:
          if(has_baro() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.baro_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BARO), buffer, true);
          }
          break;

        case FieldNumber::IMU:
          if(has_imu() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.imu_.serialize_with_id(static_cast<uint32_t>(FieldNumber::IMU), buffer, true);
          }
          break;

        case FieldNumber::BATTERY:
          if(has_battery() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.battery_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BATTERY), buffer, true);
          }
          break;

        case FieldNumber::FLASHSTATE:
          if(has_flashState() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.flashState_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FLASHSTATE), buffer, true);
          }
          break;

        case FieldNumber::DMBPRESSURE:
          if(has_dmbPressure() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.dmbPressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DMBPRESSURE), buffer, true);
          }
          break;

        case FieldNumber::PBBPRESSURE:
          if(has_pbbPressure() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.pbbPressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBBPRESSURE), buffer, true);
          }
          break;

        case FieldNumber::PBBTEMPERATURE:
          if(has_pbbTemperature() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.pbbTemperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PBBTEMPERATURE), buffer, true);
          }
          break;

        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          if(has_combustionControlStatus() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.combustionControlStatus_.serialize_with_id(static_cast<uint32_t>(FieldNumber::COMBUSTIONCONTROLSTATUS), buffer, true);
          }
          break;

        case FieldNumber::RCUPRESSURE:
          if(has_rcuPressure() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.rcuPressure_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RCUPRESSURE), buffer, true);
          }
          break;

        case FieldNumber::RCUTEMPERATURE:
          if(has_rcuTemperature() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.rcuTemperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RCUTEMPERATURE), buffer, true);
          }
          break;

        case FieldNumber::NOSLOADCELL:
          if(has_nosLoadCell() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.nosLoadCell_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NOSLOADCELL), buffer, true);
          }
          break;

        case FieldNumber::RELAYSTATUS:
          if(has_relayStatus() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.relayStatus_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RELAYSTATUS), buffer, true);
          }
          break;

        case FieldNumber::PADBOXSTATUS:
          if(has_padBoxStatus() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.padBoxStatus_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PADBOXSTATUS), buffer, true);
          }
          break;

        case FieldNumber::LAUNCHRAILLOADCELL:
          if(has_launchRailLoadCell() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.launchRailLoadCell_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LAUNCHRAILLOADCELL), buffer, true);
          }
          break;

        case FieldNumber::SOBTEMPERATURE:
          if(has_sobTemperature() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.sobTemperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOBTEMPERATURE), buffer, true);
          }
          break;

        case FieldNumber::PRESSURELOG:
          if(has_pressureLog() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.pressureLog_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PRESSURELOG), buffer, true);
          }
          break;

        default:
          break;
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::SOURCE:
            return_value = source_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TARGET:
            return_value = target_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GPS:
          case FieldNumber::BARO:
          case FieldNumber::IMU:
          case FieldNumber::BATTERY:
          case FieldNumber::FLASHSTATE:
          case FieldNumber::DMBPRESSURE:
          case FieldNumber::PBBPRESSURE:
          case FieldNumber::PBBTEMPERATURE:
          case FieldNumber::COMBUSTIONCONTROLSTATUS:
          case FieldNumber::RCUPRESSURE:
          case FieldNumber::RCUTEMPERATURE:
          case FieldNumber::NOSLOADCELL:
          case FieldNumber::RELAYSTATUS:
          case FieldNumber::PADBOXSTATUS:
          case FieldNumber::LAUNCHRAILLOADCELL:
          case FieldNumber::SOBTEMPERATURE:
          case FieldNumber::PRESSURELOG:
            return_value = deserialize_message(id_tag, buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_source();
      clear_target();
      clear_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SOURCE:
          name = SOURCE_NAME;
          break;
        case FieldNumber::TARGET:
          name = TARGET_NAME;
          break;
        case FieldNumber::GPS:
          name = GPS_NAME;
          break;
        case FieldNumber::BARO:
          name = BARO_NAME;
          break;
        case FieldNumber::IMU:
          name = IMU_NAME;
          break;
        case FieldNumber::BATTERY:
          name = BATTERY_NAME;
          break;
        case FieldNumber::FLASHSTATE:
          name = FLASHSTATE_NAME;
          break;
        case FieldNumber::DMBPRESSURE:
          name = DMBPRESSURE_NAME;
          break;
        case FieldNumber::PBBPRESSURE:
          name = PBBPRESSURE_NAME;
          break;
        case FieldNumber::PBBTEMPERATURE:
          name = PBBTEMPERATURE_NAME;
          break;
        case FieldNumber::COMBUSTIONCONTROLSTATUS:
          name = COMBUSTIONCONTROLSTATUS_NAME;
          break;
        case FieldNumber::RCUPRESSURE:
          name = RCUPRESSURE_NAME;
          break;
        case FieldNumber::RCUTEMPERATURE:
          name = RCUTEMPERATURE_NAME;
          break;
        case FieldNumber::NOSLOADCELL:
          name = NOSLOADCELL_NAME;
          break;
        case FieldNumber::RELAYSTATUS:
          name = RELAYSTATUS_NAME;
          break;
        case FieldNumber::PADBOXSTATUS:
          name = PADBOXSTATUS_NAME;
          break;
        case FieldNumber::LAUNCHRAILLOADCELL:
          name = LAUNCHRAILLOADCELL_NAME;
          break;
        case FieldNumber::SOBTEMPERATURE:
          name = SOBTEMPERATURE_NAME;
          break;
        case FieldNumber::PRESSURELOG:
          name = PRESSURELOG_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = source_.to_string(left_chars, indent_level + 2, SOURCE_NAME, true);
      left_chars = target_.to_string(left_chars, indent_level + 2, TARGET_NAME, false);
      left_chars = to_string_message(left_chars, indent_level + 2, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::enumeration<Node> source_ = static_cast<Node>(0);
      EmbeddedProto::enumeration<Node> target_ = static_cast<Node>(0);

      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        Gps gps_;
        Baro baro_;
        Imu imu_;
        Battery battery_;
        Flash flashState_;
        DmbPressure dmbPressure_;
        PbbPressure pbbPressure_;
        PbbTemperature pbbTemperature_;
        CombustionControlStatus combustionControlStatus_;
        RcuPressure rcuPressure_;
        RcuTemperature rcuTemperature_;
        NosLoadCell nosLoadCell_;
        RelayStatus relayStatus_;
        PadBoxStatus padBoxStatus_;
        LaunchRailLoadCell launchRailLoadCell_;
        SobTemperature sobTemperature_;
        PressureLog pressureLog_;
      };
      message message_;

      void init_message(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_message_)
        {
          // First delete the old object in the oneof.
          clear_message();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::GPS:
            new(&message_.gps_) Gps;
            break;

          case FieldNumber::BARO:
            new(&message_.baro_) Baro;
            break;

          case FieldNumber::IMU:
            new(&message_.imu_) Imu;
            break;

          case FieldNumber::BATTERY:
            new(&message_.battery_) Battery;
            break;

          case FieldNumber::FLASHSTATE:
            new(&message_.flashState_) Flash;
            break;

          case FieldNumber::DMBPRESSURE:
            new(&message_.dmbPressure_) DmbPressure;
            break;

          case FieldNumber::PBBPRESSURE:
            new(&message_.pbbPressure_) PbbPressure;
            break;

          case FieldNumber::PBBTEMPERATURE:
            new(&message_.pbbTemperature_) PbbTemperature;
            break;

          case FieldNumber::COMBUSTIONCONTROLSTATUS:
            new(&message_.combustionControlStatus_) CombustionControlStatus;
            break;

          case FieldNumber::RCUPRESSURE:
            new(&message_.rcuPressure_) RcuPressure;
            break;

          case FieldNumber::RCUTEMPERATURE:
            new(&message_.rcuTemperature_) RcuTemperature;
            break;

          case FieldNumber::NOSLOADCELL:
            new(&message_.nosLoadCell_) NosLoadCell;
            break;

          case FieldNumber::RELAYSTATUS:
            new(&message_.relayStatus_) RelayStatus;
            break;

          case FieldNumber::PADBOXSTATUS:
            new(&message_.padBoxStatus_) PadBoxStatus;
            break;

          case FieldNumber::LAUNCHRAILLOADCELL:
            new(&message_.launchRailLoadCell_) LaunchRailLoadCell;
            break;

          case FieldNumber::SOBTEMPERATURE:
            new(&message_.sobTemperature_) SobTemperature;
            break;

          case FieldNumber::PRESSURELOG:
            new(&message_.pressureLog_) PressureLog;
            break;

          default:
            break;
         }

         which_message_ = field_id;
      }

      void clear_message()
      {
        switch(which_message_)
        {
          case FieldNumber::GPS:
            ::EmbeddedProto::destroy_at(&message_.gps_);
            break;
          case FieldNumber::BARO:
            ::EmbeddedProto::destroy_at(&message_.baro_);
            break;
          case FieldNumber::IMU:
            ::EmbeddedProto::destroy_at(&message_.imu_);
            break;
          case FieldNumber::BATTERY:
            ::EmbeddedProto::destroy_at(&message_.battery_);
            break;
          case FieldNumber::FLASHSTATE:
            ::EmbeddedProto::destroy_at(&message_.flashState_);
            break;
          case FieldNumber::DMBPRESSURE:
            ::EmbeddedProto::destroy_at(&message_.dmbPressure_);
            break;
          case FieldNumber::PBBPRESSURE:
            ::EmbeddedProto::destroy_at(&message_.pbbPressure_);
            break;
          case FieldNumber::PBBTEMPERATURE:
            ::EmbeddedProto::destroy_at(&message_.pbbTemperature_);
            break;
          case FieldNumber::COMBUSTIONCONTROLSTATUS:
            ::EmbeddedProto::destroy_at(&message_.combustionControlStatus_);
            break;
          case FieldNumber::RCUPRESSURE:
            ::EmbeddedProto::destroy_at(&message_.rcuPressure_);
            break;
          case FieldNumber::RCUTEMPERATURE:
            ::EmbeddedProto::destroy_at(&message_.rcuTemperature_);
            break;
          case FieldNumber::NOSLOADCELL:
            ::EmbeddedProto::destroy_at(&message_.nosLoadCell_);
            break;
          case FieldNumber::RELAYSTATUS:
            ::EmbeddedProto::destroy_at(&message_.relayStatus_);
            break;
          case FieldNumber::PADBOXSTATUS:
            ::EmbeddedProto::destroy_at(&message_.padBoxStatus_);
            break;
          case FieldNumber::LAUNCHRAILLOADCELL:
            ::EmbeddedProto::destroy_at(&message_.launchRailLoadCell_);
            break;
          case FieldNumber::SOBTEMPERATURE:
            ::EmbeddedProto::destroy_at(&message_.sobTemperature_);
            break;
          case FieldNumber::PRESSURELOG:
            ::EmbeddedProto::destroy_at(&message_.pressureLog_);
            break;
          default:
            break;
        }
        which_message_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_message(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_message_)
        {
          init_message(field_id);
        }

        switch(which_message_)
        {
          case FieldNumber::GPS:
            return_value = message_.gps_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::BARO:
            return_value = message_.baro_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::IMU:
            return_value = message_.imu_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::BATTERY:
            return_value = message_.battery_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::FLASHSTATE:
            return_value = message_.flashState_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::DMBPRESSURE:
            return_value = message_.dmbPressure_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::PBBPRESSURE:
            return_value = message_.pbbPressure_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::PBBTEMPERATURE:
            return_value = message_.pbbTemperature_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::COMBUSTIONCONTROLSTATUS:
            return_value = message_.combustionControlStatus_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::RCUPRESSURE:
            return_value = message_.rcuPressure_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::RCUTEMPERATURE:
            return_value = message_.rcuTemperature_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::NOSLOADCELL:
            return_value = message_.nosLoadCell_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::RELAYSTATUS:
            return_value = message_.relayStatus_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::PADBOXSTATUS:
            return_value = message_.padBoxStatus_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::LAUNCHRAILLOADCELL:
            return_value = message_.launchRailLoadCell_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::SOBTEMPERATURE:
            return_value = message_.sobTemperature_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::PRESSURELOG:
            return_value = message_.pressureLog_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_message();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_message(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_message_)
        {
          case FieldNumber::GPS:
            left_chars = message_.gps_.to_string(left_chars, indent_level, GPS_NAME, first_field);
            break;
          case FieldNumber::BARO:
            left_chars = message_.baro_.to_string(left_chars, indent_level, BARO_NAME, first_field);
            break;
          case FieldNumber::IMU:
            left_chars = message_.imu_.to_string(left_chars, indent_level, IMU_NAME, first_field);
            break;
          case FieldNumber::BATTERY:
            left_chars = message_.battery_.to_string(left_chars, indent_level, BATTERY_NAME, first_field);
            break;
          case FieldNumber::FLASHSTATE:
            left_chars = message_.flashState_.to_string(left_chars, indent_level, FLASHSTATE_NAME, first_field);
            break;
          case FieldNumber::DMBPRESSURE:
            left_chars = message_.dmbPressure_.to_string(left_chars, indent_level, DMBPRESSURE_NAME, first_field);
            break;
          case FieldNumber::PBBPRESSURE:
            left_chars = message_.pbbPressure_.to_string(left_chars, indent_level, PBBPRESSURE_NAME, first_field);
            break;
          case FieldNumber::PBBTEMPERATURE:
            left_chars = message_.pbbTemperature_.to_string(left_chars, indent_level, PBBTEMPERATURE_NAME, first_field);
            break;
          case FieldNumber::COMBUSTIONCONTROLSTATUS:
            left_chars = message_.combustionControlStatus_.to_string(left_chars, indent_level, COMBUSTIONCONTROLSTATUS_NAME, first_field);
            break;
          case FieldNumber::RCUPRESSURE:
            left_chars = message_.rcuPressure_.to_string(left_chars, indent_level, RCUPRESSURE_NAME, first_field);
            break;
          case FieldNumber::RCUTEMPERATURE:
            left_chars = message_.rcuTemperature_.to_string(left_chars, indent_level, RCUTEMPERATURE_NAME, first_field);
            break;
          case FieldNumber::NOSLOADCELL:
            left_chars = message_.nosLoadCell_.to_string(left_chars, indent_level, NOSLOADCELL_NAME, first_field);
            break;
          case FieldNumber::RELAYSTATUS:
            left_chars = message_.relayStatus_.to_string(left_chars, indent_level, RELAYSTATUS_NAME, first_field);
            break;
          case FieldNumber::PADBOXSTATUS:
            left_chars = message_.padBoxStatus_.to_string(left_chars, indent_level, PADBOXSTATUS_NAME, first_field);
            break;
          case FieldNumber::LAUNCHRAILLOADCELL:
            left_chars = message_.launchRailLoadCell_.to_string(left_chars, indent_level, LAUNCHRAILLOADCELL_NAME, first_field);
            break;
          case FieldNumber::SOBTEMPERATURE:
            left_chars = message_.sobTemperature_.to_string(left_chars, indent_level, SOBTEMPERATURE_NAME, first_field);
            break;
          case FieldNumber::PRESSURELOG:
            left_chars = message_.pressureLog_.to_string(left_chars, indent_level, PRESSURELOG_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace Proto
#endif // TELEMETRYMESSAGE_H