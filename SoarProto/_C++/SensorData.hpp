/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: SensorData.proto
 */

// This file is generated. Please do not edit!
#ifndef SENSORDATA_H
#define SENSORDATA_H

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

namespace Proto {

class SensorLoggingRate final: public ::EmbeddedProto::MessageInterface
{
  public:
    SensorLoggingRate() = default;
    SensorLoggingRate(const SensorLoggingRate& rhs )
    {
      set_changeLoggingRate(rhs.get_changeLoggingRate());
      set_newSensorLoggingRate(rhs.get_newSensorLoggingRate());
    }

    SensorLoggingRate(const SensorLoggingRate&& rhs ) noexcept
    {
      set_changeLoggingRate(rhs.get_changeLoggingRate());
      set_newSensorLoggingRate(rhs.get_newSensorLoggingRate());
    }

    ~SensorLoggingRate() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      CHANGELOGGINGRATE = 1,
      NEWSENSORLOGGINGRATE = 2
    };

    SensorLoggingRate& operator=(const SensorLoggingRate& rhs)
    {
      set_changeLoggingRate(rhs.get_changeLoggingRate());
      set_newSensorLoggingRate(rhs.get_newSensorLoggingRate());
      return *this;
    }

    SensorLoggingRate& operator=(const SensorLoggingRate&& rhs) noexcept
    {
      set_changeLoggingRate(rhs.get_changeLoggingRate());
      set_newSensorLoggingRate(rhs.get_newSensorLoggingRate());
      return *this;
    }

    static constexpr char const* CHANGELOGGINGRATE_NAME = "changeLoggingRate";
    inline void clear_changeLoggingRate() { changeLoggingRate_.clear(); }
    inline void set_changeLoggingRate(const bool& value) { changeLoggingRate_ = value; }
    inline void set_changeLoggingRate(const bool&& value) { changeLoggingRate_ = value; }
    inline bool& mutable_changeLoggingRate() { return changeLoggingRate_.get(); }
    inline const bool& get_changeLoggingRate() const { return changeLoggingRate_.get(); }
    inline bool changeLoggingRate() const { return changeLoggingRate_.get(); }

    static constexpr char const* NEWSENSORLOGGINGRATE_NAME = "newSensorLoggingRate";
    inline void clear_newSensorLoggingRate() { newSensorLoggingRate_.clear(); }
    inline void set_newSensorLoggingRate(const uint32_t& value) { newSensorLoggingRate_ = value; }
    inline void set_newSensorLoggingRate(const uint32_t&& value) { newSensorLoggingRate_ = value; }
    inline uint32_t& mutable_newSensorLoggingRate() { return newSensorLoggingRate_.get(); }
    inline const uint32_t& get_newSensorLoggingRate() const { return newSensorLoggingRate_.get(); }
    inline uint32_t newSensorLoggingRate() const { return newSensorLoggingRate_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((false != changeLoggingRate_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = changeLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::CHANGELOGGINGRATE), buffer, false);
      }

      if((0U != newSensorLoggingRate_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = newSensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NEWSENSORLOGGINGRATE), buffer, false);
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
          case FieldNumber::CHANGELOGGINGRATE:
            return_value = changeLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NEWSENSORLOGGINGRATE:
            return_value = newSensorLoggingRate_.deserialize_check_type(buffer, wire_type);
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
      clear_changeLoggingRate();
      clear_newSensorLoggingRate();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::CHANGELOGGINGRATE:
          name = CHANGELOGGINGRATE_NAME;
          break;
        case FieldNumber::NEWSENSORLOGGINGRATE:
          name = NEWSENSORLOGGINGRATE_NAME;
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

      left_chars = changeLoggingRate_.to_string(left_chars, indent_level + 2, CHANGELOGGINGRATE_NAME, true);
      left_chars = newSensorLoggingRate_.to_string(left_chars, indent_level + 2, NEWSENSORLOGGINGRATE_NAME, false);
  
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


      EmbeddedProto::boolean changeLoggingRate_ = false;
      EmbeddedProto::uint32 newSensorLoggingRate_ = 0U;

};

class Accelerometer final: public ::EmbeddedProto::MessageInterface
{
  public:
    Accelerometer() = default;
    Accelerometer(const Accelerometer& rhs )
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    Accelerometer(const Accelerometer&& rhs ) noexcept
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    ~Accelerometer() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      ACCEL_X = 1,
      ACCEL_Y = 2,
      ACCEL_Z = 3,
      SENSORLOGGINGRATE = 4,
      LOGGINGIDX = 5
    };

    Accelerometer& operator=(const Accelerometer& rhs)
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    Accelerometer& operator=(const Accelerometer&& rhs) noexcept
    {
      set_accel_x(rhs.get_accel_x());
      set_accel_y(rhs.get_accel_y());
      set_accel_z(rhs.get_accel_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
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

    static constexpr char const* SENSORLOGGINGRATE_NAME = "sensorLoggingRate";
    inline void clear_sensorLoggingRate() { sensorLoggingRate_.clear(); }
    inline void set_sensorLoggingRate(const SensorLoggingRate& value) { sensorLoggingRate_ = value; }
    inline void set_sensorLoggingRate(const SensorLoggingRate&& value) { sensorLoggingRate_ = value; }
    inline SensorLoggingRate& mutable_sensorLoggingRate() { return sensorLoggingRate_; }
    inline const SensorLoggingRate& get_sensorLoggingRate() const { return sensorLoggingRate_; }
    inline const SensorLoggingRate& sensorLoggingRate() const { return sensorLoggingRate_; }

    static constexpr char const* LOGGINGIDX_NAME = "LoggingIdx";
    inline void clear_LoggingIdx() { LoggingIdx_.clear(); }
    inline void set_LoggingIdx(const int32_t& value) { LoggingIdx_ = value; }
    inline void set_LoggingIdx(const int32_t&& value) { LoggingIdx_ = value; }
    inline int32_t& mutable_LoggingIdx() { return LoggingIdx_.get(); }
    inline const int32_t& get_LoggingIdx() const { return LoggingIdx_.get(); }
    inline int32_t LoggingIdx() const { return LoggingIdx_.get(); }


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

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSORLOGGINGRATE), buffer, false);
      }

      if((0 != LoggingIdx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LoggingIdx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGINGIDX), buffer, false);
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

          case FieldNumber::SENSORLOGGINGRATE:
            return_value = sensorLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGINGIDX:
            return_value = LoggingIdx_.deserialize_check_type(buffer, wire_type);
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
      clear_sensorLoggingRate();
      clear_LoggingIdx();

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
        case FieldNumber::SENSORLOGGINGRATE:
          name = SENSORLOGGINGRATE_NAME;
          break;
        case FieldNumber::LOGGINGIDX:
          name = LOGGINGIDX_NAME;
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
      left_chars = sensorLoggingRate_.to_string(left_chars, indent_level + 2, SENSORLOGGINGRATE_NAME, false);
      left_chars = LoggingIdx_.to_string(left_chars, indent_level + 2, LOGGINGIDX_NAME, false);
  
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
      SensorLoggingRate sensorLoggingRate_;
      EmbeddedProto::int32 LoggingIdx_ = 0;

};

class Barometer final: public ::EmbeddedProto::MessageInterface
{
  public:
    Barometer() = default;
    Barometer(const Barometer& rhs )
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    Barometer(const Barometer&& rhs ) noexcept
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    ~Barometer() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      BARO_PRESSURE = 1,
      BARO_TEMPERATURE = 2,
      SENSORLOGGINGRATE = 3,
      LOGGINGIDX = 4
    };

    Barometer& operator=(const Barometer& rhs)
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    Barometer& operator=(const Barometer&& rhs) noexcept
    {
      set_baro_pressure(rhs.get_baro_pressure());
      set_baro_temperature(rhs.get_baro_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
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

    static constexpr char const* SENSORLOGGINGRATE_NAME = "sensorLoggingRate";
    inline void clear_sensorLoggingRate() { sensorLoggingRate_.clear(); }
    inline void set_sensorLoggingRate(const SensorLoggingRate& value) { sensorLoggingRate_ = value; }
    inline void set_sensorLoggingRate(const SensorLoggingRate&& value) { sensorLoggingRate_ = value; }
    inline SensorLoggingRate& mutable_sensorLoggingRate() { return sensorLoggingRate_; }
    inline const SensorLoggingRate& get_sensorLoggingRate() const { return sensorLoggingRate_; }
    inline const SensorLoggingRate& sensorLoggingRate() const { return sensorLoggingRate_; }

    static constexpr char const* LOGGINGIDX_NAME = "LoggingIdx";
    inline void clear_LoggingIdx() { LoggingIdx_.clear(); }
    inline void set_LoggingIdx(const int32_t& value) { LoggingIdx_ = value; }
    inline void set_LoggingIdx(const int32_t&& value) { LoggingIdx_ = value; }
    inline int32_t& mutable_LoggingIdx() { return LoggingIdx_.get(); }
    inline const int32_t& get_LoggingIdx() const { return LoggingIdx_.get(); }
    inline int32_t LoggingIdx() const { return LoggingIdx_.get(); }


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

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSORLOGGINGRATE), buffer, false);
      }

      if((0 != LoggingIdx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LoggingIdx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGINGIDX), buffer, false);
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

          case FieldNumber::SENSORLOGGINGRATE:
            return_value = sensorLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGINGIDX:
            return_value = LoggingIdx_.deserialize_check_type(buffer, wire_type);
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
      clear_sensorLoggingRate();
      clear_LoggingIdx();

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
        case FieldNumber::SENSORLOGGINGRATE:
          name = SENSORLOGGINGRATE_NAME;
          break;
        case FieldNumber::LOGGINGIDX:
          name = LOGGINGIDX_NAME;
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
      left_chars = sensorLoggingRate_.to_string(left_chars, indent_level + 2, SENSORLOGGINGRATE_NAME, false);
      left_chars = LoggingIdx_.to_string(left_chars, indent_level + 2, LOGGINGIDX_NAME, false);
  
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
      SensorLoggingRate sensorLoggingRate_;
      EmbeddedProto::int32 LoggingIdx_ = 0;

};

class Gyroscope final: public ::EmbeddedProto::MessageInterface
{
  public:
    Gyroscope() = default;
    Gyroscope(const Gyroscope& rhs )
    {
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    Gyroscope(const Gyroscope&& rhs ) noexcept
    {
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    ~Gyroscope() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      GYRO_X = 1,
      GYRO_Y = 2,
      GYRO_Z = 3,
      SENSORLOGGINGRATE = 4,
      LOGGINGIDX = 5
    };

    Gyroscope& operator=(const Gyroscope& rhs)
    {
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    Gyroscope& operator=(const Gyroscope&& rhs) noexcept
    {
      set_gyro_x(rhs.get_gyro_x());
      set_gyro_y(rhs.get_gyro_y());
      set_gyro_z(rhs.get_gyro_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

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

    static constexpr char const* SENSORLOGGINGRATE_NAME = "sensorLoggingRate";
    inline void clear_sensorLoggingRate() { sensorLoggingRate_.clear(); }
    inline void set_sensorLoggingRate(const SensorLoggingRate& value) { sensorLoggingRate_ = value; }
    inline void set_sensorLoggingRate(const SensorLoggingRate&& value) { sensorLoggingRate_ = value; }
    inline SensorLoggingRate& mutable_sensorLoggingRate() { return sensorLoggingRate_; }
    inline const SensorLoggingRate& get_sensorLoggingRate() const { return sensorLoggingRate_; }
    inline const SensorLoggingRate& sensorLoggingRate() const { return sensorLoggingRate_; }

    static constexpr char const* LOGGINGIDX_NAME = "LoggingIdx";
    inline void clear_LoggingIdx() { LoggingIdx_.clear(); }
    inline void set_LoggingIdx(const int32_t& value) { LoggingIdx_ = value; }
    inline void set_LoggingIdx(const int32_t&& value) { LoggingIdx_ = value; }
    inline int32_t& mutable_LoggingIdx() { return LoggingIdx_.get(); }
    inline const int32_t& get_LoggingIdx() const { return LoggingIdx_.get(); }
    inline int32_t LoggingIdx() const { return LoggingIdx_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

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

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSORLOGGINGRATE), buffer, false);
      }

      if((0 != LoggingIdx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LoggingIdx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGINGIDX), buffer, false);
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
          case FieldNumber::GYRO_X:
            return_value = gyro_x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GYRO_Y:
            return_value = gyro_y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::GYRO_Z:
            return_value = gyro_z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSORLOGGINGRATE:
            return_value = sensorLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGINGIDX:
            return_value = LoggingIdx_.deserialize_check_type(buffer, wire_type);
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
      clear_gyro_x();
      clear_gyro_y();
      clear_gyro_z();
      clear_sensorLoggingRate();
      clear_LoggingIdx();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::GYRO_X:
          name = GYRO_X_NAME;
          break;
        case FieldNumber::GYRO_Y:
          name = GYRO_Y_NAME;
          break;
        case FieldNumber::GYRO_Z:
          name = GYRO_Z_NAME;
          break;
        case FieldNumber::SENSORLOGGINGRATE:
          name = SENSORLOGGINGRATE_NAME;
          break;
        case FieldNumber::LOGGINGIDX:
          name = LOGGINGIDX_NAME;
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

      left_chars = gyro_x_.to_string(left_chars, indent_level + 2, GYRO_X_NAME, true);
      left_chars = gyro_y_.to_string(left_chars, indent_level + 2, GYRO_Y_NAME, false);
      left_chars = gyro_z_.to_string(left_chars, indent_level + 2, GYRO_Z_NAME, false);
      left_chars = sensorLoggingRate_.to_string(left_chars, indent_level + 2, SENSORLOGGINGRATE_NAME, false);
      left_chars = LoggingIdx_.to_string(left_chars, indent_level + 2, LOGGINGIDX_NAME, false);
  
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


      EmbeddedProto::int32 gyro_x_ = 0;
      EmbeddedProto::int32 gyro_y_ = 0;
      EmbeddedProto::int32 gyro_z_ = 0;
      SensorLoggingRate sensorLoggingRate_;
      EmbeddedProto::int32 LoggingIdx_ = 0;

};

class Magnetometer final: public ::EmbeddedProto::MessageInterface
{
  public:
    Magnetometer() = default;
    Magnetometer(const Magnetometer& rhs )
    {
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    Magnetometer(const Magnetometer&& rhs ) noexcept
    {
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    ~Magnetometer() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      MAG_X = 1,
      MAG_Y = 2,
      MAG_Z = 3,
      SENSORLOGGINGRATE = 4,
      LOGGINGIDX = 5
    };

    Magnetometer& operator=(const Magnetometer& rhs)
    {
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    Magnetometer& operator=(const Magnetometer&& rhs) noexcept
    {
      set_mag_x(rhs.get_mag_x());
      set_mag_y(rhs.get_mag_y());
      set_mag_z(rhs.get_mag_z());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

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

    static constexpr char const* SENSORLOGGINGRATE_NAME = "sensorLoggingRate";
    inline void clear_sensorLoggingRate() { sensorLoggingRate_.clear(); }
    inline void set_sensorLoggingRate(const SensorLoggingRate& value) { sensorLoggingRate_ = value; }
    inline void set_sensorLoggingRate(const SensorLoggingRate&& value) { sensorLoggingRate_ = value; }
    inline SensorLoggingRate& mutable_sensorLoggingRate() { return sensorLoggingRate_; }
    inline const SensorLoggingRate& get_sensorLoggingRate() const { return sensorLoggingRate_; }
    inline const SensorLoggingRate& sensorLoggingRate() const { return sensorLoggingRate_; }

    static constexpr char const* LOGGINGIDX_NAME = "LoggingIdx";
    inline void clear_LoggingIdx() { LoggingIdx_.clear(); }
    inline void set_LoggingIdx(const int32_t& value) { LoggingIdx_ = value; }
    inline void set_LoggingIdx(const int32_t&& value) { LoggingIdx_ = value; }
    inline int32_t& mutable_LoggingIdx() { return LoggingIdx_.get(); }
    inline const int32_t& get_LoggingIdx() const { return LoggingIdx_.get(); }
    inline int32_t LoggingIdx() const { return LoggingIdx_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

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

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSORLOGGINGRATE), buffer, false);
      }

      if((0 != LoggingIdx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LoggingIdx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGINGIDX), buffer, false);
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
          case FieldNumber::MAG_X:
            return_value = mag_x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MAG_Y:
            return_value = mag_y_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::MAG_Z:
            return_value = mag_z_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSORLOGGINGRATE:
            return_value = sensorLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGINGIDX:
            return_value = LoggingIdx_.deserialize_check_type(buffer, wire_type);
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
      clear_mag_x();
      clear_mag_y();
      clear_mag_z();
      clear_sensorLoggingRate();
      clear_LoggingIdx();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::MAG_X:
          name = MAG_X_NAME;
          break;
        case FieldNumber::MAG_Y:
          name = MAG_Y_NAME;
          break;
        case FieldNumber::MAG_Z:
          name = MAG_Z_NAME;
          break;
        case FieldNumber::SENSORLOGGINGRATE:
          name = SENSORLOGGINGRATE_NAME;
          break;
        case FieldNumber::LOGGINGIDX:
          name = LOGGINGIDX_NAME;
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

      left_chars = mag_x_.to_string(left_chars, indent_level + 2, MAG_X_NAME, true);
      left_chars = mag_y_.to_string(left_chars, indent_level + 2, MAG_Y_NAME, false);
      left_chars = mag_z_.to_string(left_chars, indent_level + 2, MAG_Z_NAME, false);
      left_chars = sensorLoggingRate_.to_string(left_chars, indent_level + 2, SENSORLOGGINGRATE_NAME, false);
      left_chars = LoggingIdx_.to_string(left_chars, indent_level + 2, LOGGINGIDX_NAME, false);
  
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


      EmbeddedProto::int32 mag_x_ = 0;
      EmbeddedProto::int32 mag_y_ = 0;
      EmbeddedProto::int32 mag_z_ = 0;
      SensorLoggingRate sensorLoggingRate_;
      EmbeddedProto::int32 LoggingIdx_ = 0;

};

class Thermocouple final: public ::EmbeddedProto::MessageInterface
{
  public:
    Thermocouple() = default;
    Thermocouple(const Thermocouple& rhs )
    {
      set_termo_temperature(rhs.get_termo_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    Thermocouple(const Thermocouple&& rhs ) noexcept
    {
      set_termo_temperature(rhs.get_termo_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
    }

    ~Thermocouple() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TERMO_TEMPERATURE = 1,
      SENSORLOGGINGRATE = 2,
      LOGGINGIDX = 3
    };

    Thermocouple& operator=(const Thermocouple& rhs)
    {
      set_termo_temperature(rhs.get_termo_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    Thermocouple& operator=(const Thermocouple&& rhs) noexcept
    {
      set_termo_temperature(rhs.get_termo_temperature());
      set_sensorLoggingRate(rhs.get_sensorLoggingRate());
      set_LoggingIdx(rhs.get_LoggingIdx());
      return *this;
    }

    static constexpr char const* TERMO_TEMPERATURE_NAME = "termo_temperature";
    inline void clear_termo_temperature() { termo_temperature_.clear(); }
    inline void set_termo_temperature(const int32_t& value) { termo_temperature_ = value; }
    inline void set_termo_temperature(const int32_t&& value) { termo_temperature_ = value; }
    inline int32_t& mutable_termo_temperature() { return termo_temperature_.get(); }
    inline const int32_t& get_termo_temperature() const { return termo_temperature_.get(); }
    inline int32_t termo_temperature() const { return termo_temperature_.get(); }

    static constexpr char const* SENSORLOGGINGRATE_NAME = "sensorLoggingRate";
    inline void clear_sensorLoggingRate() { sensorLoggingRate_.clear(); }
    inline void set_sensorLoggingRate(const SensorLoggingRate& value) { sensorLoggingRate_ = value; }
    inline void set_sensorLoggingRate(const SensorLoggingRate&& value) { sensorLoggingRate_ = value; }
    inline SensorLoggingRate& mutable_sensorLoggingRate() { return sensorLoggingRate_; }
    inline const SensorLoggingRate& get_sensorLoggingRate() const { return sensorLoggingRate_; }
    inline const SensorLoggingRate& sensorLoggingRate() const { return sensorLoggingRate_; }

    static constexpr char const* LOGGINGIDX_NAME = "LoggingIdx";
    inline void clear_LoggingIdx() { LoggingIdx_.clear(); }
    inline void set_LoggingIdx(const int32_t& value) { LoggingIdx_ = value; }
    inline void set_LoggingIdx(const int32_t&& value) { LoggingIdx_ = value; }
    inline int32_t& mutable_LoggingIdx() { return LoggingIdx_.get(); }
    inline const int32_t& get_LoggingIdx() const { return LoggingIdx_.get(); }
    inline int32_t LoggingIdx() const { return LoggingIdx_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != termo_temperature_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = termo_temperature_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TERMO_TEMPERATURE), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensorLoggingRate_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSORLOGGINGRATE), buffer, false);
      }

      if((0 != LoggingIdx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LoggingIdx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::LOGGINGIDX), buffer, false);
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
          case FieldNumber::TERMO_TEMPERATURE:
            return_value = termo_temperature_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSORLOGGINGRATE:
            return_value = sensorLoggingRate_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::LOGGINGIDX:
            return_value = LoggingIdx_.deserialize_check_type(buffer, wire_type);
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
      clear_termo_temperature();
      clear_sensorLoggingRate();
      clear_LoggingIdx();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TERMO_TEMPERATURE:
          name = TERMO_TEMPERATURE_NAME;
          break;
        case FieldNumber::SENSORLOGGINGRATE:
          name = SENSORLOGGINGRATE_NAME;
          break;
        case FieldNumber::LOGGINGIDX:
          name = LOGGINGIDX_NAME;
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

      left_chars = termo_temperature_.to_string(left_chars, indent_level + 2, TERMO_TEMPERATURE_NAME, true);
      left_chars = sensorLoggingRate_.to_string(left_chars, indent_level + 2, SENSORLOGGINGRATE_NAME, false);
      left_chars = LoggingIdx_.to_string(left_chars, indent_level + 2, LOGGINGIDX_NAME, false);
  
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


      EmbeddedProto::int32 termo_temperature_ = 0;
      SensorLoggingRate sensorLoggingRate_;
      EmbeddedProto::int32 LoggingIdx_ = 0;

};

class SensorData final: public ::EmbeddedProto::MessageInterface
{
  public:
    SensorData() = default;
    SensorData(const SensorData& rhs )
    {
      set_timestamp(rhs.get_timestamp());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::BAROMETERMESSAGE:
          set_barometerMessage(rhs.get_barometerMessage());
          break;

        case FieldNumber::ACCELEROMETERMESSAGE:
          set_accelerometerMessage(rhs.get_accelerometerMessage());
          break;

        case FieldNumber::MAGNETOMETERMESSAGE:
          set_magnetometerMessage(rhs.get_magnetometerMessage());
          break;

        case FieldNumber::GYROSCOPERMESSAGE:
          set_gyroscoperMessage(rhs.get_gyroscoperMessage());
          break;

        case FieldNumber::THERMOCOUPLEMESSAGE:
          set_thermocoupleMessage(rhs.get_thermocoupleMessage());
          break;

        default:
          break;
      }

    }

    SensorData(const SensorData&& rhs ) noexcept
    {
      set_timestamp(rhs.get_timestamp());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::BAROMETERMESSAGE:
          set_barometerMessage(rhs.get_barometerMessage());
          break;

        case FieldNumber::ACCELEROMETERMESSAGE:
          set_accelerometerMessage(rhs.get_accelerometerMessage());
          break;

        case FieldNumber::MAGNETOMETERMESSAGE:
          set_magnetometerMessage(rhs.get_magnetometerMessage());
          break;

        case FieldNumber::GYROSCOPERMESSAGE:
          set_gyroscoperMessage(rhs.get_gyroscoperMessage());
          break;

        case FieldNumber::THERMOCOUPLEMESSAGE:
          set_thermocoupleMessage(rhs.get_thermocoupleMessage());
          break;

        default:
          break;
      }

    }

    ~SensorData() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TIMESTAMP = 1,
      BAROMETERMESSAGE = 2,
      ACCELEROMETERMESSAGE = 3,
      MAGNETOMETERMESSAGE = 4,
      GYROSCOPERMESSAGE = 5,
      THERMOCOUPLEMESSAGE = 6
    };

    SensorData& operator=(const SensorData& rhs)
    {
      set_timestamp(rhs.get_timestamp());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::BAROMETERMESSAGE:
          set_barometerMessage(rhs.get_barometerMessage());
          break;

        case FieldNumber::ACCELEROMETERMESSAGE:
          set_accelerometerMessage(rhs.get_accelerometerMessage());
          break;

        case FieldNumber::MAGNETOMETERMESSAGE:
          set_magnetometerMessage(rhs.get_magnetometerMessage());
          break;

        case FieldNumber::GYROSCOPERMESSAGE:
          set_gyroscoperMessage(rhs.get_gyroscoperMessage());
          break;

        case FieldNumber::THERMOCOUPLEMESSAGE:
          set_thermocoupleMessage(rhs.get_thermocoupleMessage());
          break;

        default:
          break;
      }

      return *this;
    }

    SensorData& operator=(const SensorData&& rhs) noexcept
    {
      set_timestamp(rhs.get_timestamp());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::BAROMETERMESSAGE:
          set_barometerMessage(rhs.get_barometerMessage());
          break;

        case FieldNumber::ACCELEROMETERMESSAGE:
          set_accelerometerMessage(rhs.get_accelerometerMessage());
          break;

        case FieldNumber::MAGNETOMETERMESSAGE:
          set_magnetometerMessage(rhs.get_magnetometerMessage());
          break;

        case FieldNumber::GYROSCOPERMESSAGE:
          set_gyroscoperMessage(rhs.get_gyroscoperMessage());
          break;

        case FieldNumber::THERMOCOUPLEMESSAGE:
          set_thermocoupleMessage(rhs.get_thermocoupleMessage());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* TIMESTAMP_NAME = "timestamp";
    inline void clear_timestamp() { timestamp_.clear(); }
    inline void set_timestamp(const uint32_t& value) { timestamp_ = value; }
    inline void set_timestamp(const uint32_t&& value) { timestamp_ = value; }
    inline uint32_t& mutable_timestamp() { return timestamp_.get(); }
    inline const uint32_t& get_timestamp() const { return timestamp_.get(); }
    inline uint32_t timestamp() const { return timestamp_.get(); }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* BAROMETERMESSAGE_NAME = "barometerMessage";
    inline bool has_barometerMessage() const
    {
      return FieldNumber::BAROMETERMESSAGE == which_message_;
    }
    inline void clear_barometerMessage()
    {
      if(FieldNumber::BAROMETERMESSAGE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.barometerMessage_.~Barometer();
      }
    }
    inline void set_barometerMessage(const Barometer& value)
    {
      if(FieldNumber::BAROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::BAROMETERMESSAGE);
      }
      message_.barometerMessage_ = value;
    }
    inline void set_barometerMessage(const Barometer&& value)
    {
      if(FieldNumber::BAROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::BAROMETERMESSAGE);
      }
      message_.barometerMessage_ = value;
    }
    inline Barometer& mutable_barometerMessage()
    {
      if(FieldNumber::BAROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::BAROMETERMESSAGE);
      }
      return message_.barometerMessage_;
    }
    inline const Barometer& get_barometerMessage() const { return message_.barometerMessage_; }
    inline const Barometer& barometerMessage() const { return message_.barometerMessage_; }

    static constexpr char const* ACCELEROMETERMESSAGE_NAME = "accelerometerMessage";
    inline bool has_accelerometerMessage() const
    {
      return FieldNumber::ACCELEROMETERMESSAGE == which_message_;
    }
    inline void clear_accelerometerMessage()
    {
      if(FieldNumber::ACCELEROMETERMESSAGE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.accelerometerMessage_.~Accelerometer();
      }
    }
    inline void set_accelerometerMessage(const Accelerometer& value)
    {
      if(FieldNumber::ACCELEROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::ACCELEROMETERMESSAGE);
      }
      message_.accelerometerMessage_ = value;
    }
    inline void set_accelerometerMessage(const Accelerometer&& value)
    {
      if(FieldNumber::ACCELEROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::ACCELEROMETERMESSAGE);
      }
      message_.accelerometerMessage_ = value;
    }
    inline Accelerometer& mutable_accelerometerMessage()
    {
      if(FieldNumber::ACCELEROMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::ACCELEROMETERMESSAGE);
      }
      return message_.accelerometerMessage_;
    }
    inline const Accelerometer& get_accelerometerMessage() const { return message_.accelerometerMessage_; }
    inline const Accelerometer& accelerometerMessage() const { return message_.accelerometerMessage_; }

    static constexpr char const* MAGNETOMETERMESSAGE_NAME = "magnetometerMessage";
    inline bool has_magnetometerMessage() const
    {
      return FieldNumber::MAGNETOMETERMESSAGE == which_message_;
    }
    inline void clear_magnetometerMessage()
    {
      if(FieldNumber::MAGNETOMETERMESSAGE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.magnetometerMessage_.~Magnetometer();
      }
    }
    inline void set_magnetometerMessage(const Magnetometer& value)
    {
      if(FieldNumber::MAGNETOMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::MAGNETOMETERMESSAGE);
      }
      message_.magnetometerMessage_ = value;
    }
    inline void set_magnetometerMessage(const Magnetometer&& value)
    {
      if(FieldNumber::MAGNETOMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::MAGNETOMETERMESSAGE);
      }
      message_.magnetometerMessage_ = value;
    }
    inline Magnetometer& mutable_magnetometerMessage()
    {
      if(FieldNumber::MAGNETOMETERMESSAGE != which_message_)
      {
        init_message(FieldNumber::MAGNETOMETERMESSAGE);
      }
      return message_.magnetometerMessage_;
    }
    inline const Magnetometer& get_magnetometerMessage() const { return message_.magnetometerMessage_; }
    inline const Magnetometer& magnetometerMessage() const { return message_.magnetometerMessage_; }

    static constexpr char const* GYROSCOPERMESSAGE_NAME = "gyroscoperMessage";
    inline bool has_gyroscoperMessage() const
    {
      return FieldNumber::GYROSCOPERMESSAGE == which_message_;
    }
    inline void clear_gyroscoperMessage()
    {
      if(FieldNumber::GYROSCOPERMESSAGE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.gyroscoperMessage_.~Gyroscope();
      }
    }
    inline void set_gyroscoperMessage(const Gyroscope& value)
    {
      if(FieldNumber::GYROSCOPERMESSAGE != which_message_)
      {
        init_message(FieldNumber::GYROSCOPERMESSAGE);
      }
      message_.gyroscoperMessage_ = value;
    }
    inline void set_gyroscoperMessage(const Gyroscope&& value)
    {
      if(FieldNumber::GYROSCOPERMESSAGE != which_message_)
      {
        init_message(FieldNumber::GYROSCOPERMESSAGE);
      }
      message_.gyroscoperMessage_ = value;
    }
    inline Gyroscope& mutable_gyroscoperMessage()
    {
      if(FieldNumber::GYROSCOPERMESSAGE != which_message_)
      {
        init_message(FieldNumber::GYROSCOPERMESSAGE);
      }
      return message_.gyroscoperMessage_;
    }
    inline const Gyroscope& get_gyroscoperMessage() const { return message_.gyroscoperMessage_; }
    inline const Gyroscope& gyroscoperMessage() const { return message_.gyroscoperMessage_; }

    static constexpr char const* THERMOCOUPLEMESSAGE_NAME = "thermocoupleMessage";
    inline bool has_thermocoupleMessage() const
    {
      return FieldNumber::THERMOCOUPLEMESSAGE == which_message_;
    }
    inline void clear_thermocoupleMessage()
    {
      if(FieldNumber::THERMOCOUPLEMESSAGE == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.thermocoupleMessage_.~Thermocouple();
      }
    }
    inline void set_thermocoupleMessage(const Thermocouple& value)
    {
      if(FieldNumber::THERMOCOUPLEMESSAGE != which_message_)
      {
        init_message(FieldNumber::THERMOCOUPLEMESSAGE);
      }
      message_.thermocoupleMessage_ = value;
    }
    inline void set_thermocoupleMessage(const Thermocouple&& value)
    {
      if(FieldNumber::THERMOCOUPLEMESSAGE != which_message_)
      {
        init_message(FieldNumber::THERMOCOUPLEMESSAGE);
      }
      message_.thermocoupleMessage_ = value;
    }
    inline Thermocouple& mutable_thermocoupleMessage()
    {
      if(FieldNumber::THERMOCOUPLEMESSAGE != which_message_)
      {
        init_message(FieldNumber::THERMOCOUPLEMESSAGE);
      }
      return message_.thermocoupleMessage_;
    }
    inline const Thermocouple& get_thermocoupleMessage() const { return message_.thermocoupleMessage_; }
    inline const Thermocouple& thermocoupleMessage() const { return message_.thermocoupleMessage_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != timestamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timestamp_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TIMESTAMP), buffer, false);
      }

      switch(which_message_)
      {
        case FieldNumber::BAROMETERMESSAGE:
          if(has_barometerMessage() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.barometerMessage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::BAROMETERMESSAGE), buffer, true);
          }
          break;

        case FieldNumber::ACCELEROMETERMESSAGE:
          if(has_accelerometerMessage() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.accelerometerMessage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::ACCELEROMETERMESSAGE), buffer, true);
          }
          break;

        case FieldNumber::MAGNETOMETERMESSAGE:
          if(has_magnetometerMessage() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.magnetometerMessage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MAGNETOMETERMESSAGE), buffer, true);
          }
          break;

        case FieldNumber::GYROSCOPERMESSAGE:
          if(has_gyroscoperMessage() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.gyroscoperMessage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::GYROSCOPERMESSAGE), buffer, true);
          }
          break;

        case FieldNumber::THERMOCOUPLEMESSAGE:
          if(has_thermocoupleMessage() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.thermocoupleMessage_.serialize_with_id(static_cast<uint32_t>(FieldNumber::THERMOCOUPLEMESSAGE), buffer, true);
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
          case FieldNumber::TIMESTAMP:
            return_value = timestamp_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::BAROMETERMESSAGE:
          case FieldNumber::ACCELEROMETERMESSAGE:
          case FieldNumber::MAGNETOMETERMESSAGE:
          case FieldNumber::GYROSCOPERMESSAGE:
          case FieldNumber::THERMOCOUPLEMESSAGE:
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
      clear_timestamp();
      clear_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TIMESTAMP:
          name = TIMESTAMP_NAME;
          break;
        case FieldNumber::BAROMETERMESSAGE:
          name = BAROMETERMESSAGE_NAME;
          break;
        case FieldNumber::ACCELEROMETERMESSAGE:
          name = ACCELEROMETERMESSAGE_NAME;
          break;
        case FieldNumber::MAGNETOMETERMESSAGE:
          name = MAGNETOMETERMESSAGE_NAME;
          break;
        case FieldNumber::GYROSCOPERMESSAGE:
          name = GYROSCOPERMESSAGE_NAME;
          break;
        case FieldNumber::THERMOCOUPLEMESSAGE:
          name = THERMOCOUPLEMESSAGE_NAME;
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

      left_chars = timestamp_.to_string(left_chars, indent_level + 2, TIMESTAMP_NAME, true);
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


      EmbeddedProto::uint32 timestamp_ = 0U;

      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        Barometer barometerMessage_;
        Accelerometer accelerometerMessage_;
        Magnetometer magnetometerMessage_;
        Gyroscope gyroscoperMessage_;
        Thermocouple thermocoupleMessage_;
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
          case FieldNumber::BAROMETERMESSAGE:
            new(&message_.barometerMessage_) Barometer;
            break;

          case FieldNumber::ACCELEROMETERMESSAGE:
            new(&message_.accelerometerMessage_) Accelerometer;
            break;

          case FieldNumber::MAGNETOMETERMESSAGE:
            new(&message_.magnetometerMessage_) Magnetometer;
            break;

          case FieldNumber::GYROSCOPERMESSAGE:
            new(&message_.gyroscoperMessage_) Gyroscope;
            break;

          case FieldNumber::THERMOCOUPLEMESSAGE:
            new(&message_.thermocoupleMessage_) Thermocouple;
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
          case FieldNumber::BAROMETERMESSAGE:
            ::EmbeddedProto::destroy_at(&message_.barometerMessage_);
            break;
          case FieldNumber::ACCELEROMETERMESSAGE:
            ::EmbeddedProto::destroy_at(&message_.accelerometerMessage_);
            break;
          case FieldNumber::MAGNETOMETERMESSAGE:
            ::EmbeddedProto::destroy_at(&message_.magnetometerMessage_);
            break;
          case FieldNumber::GYROSCOPERMESSAGE:
            ::EmbeddedProto::destroy_at(&message_.gyroscoperMessage_);
            break;
          case FieldNumber::THERMOCOUPLEMESSAGE:
            ::EmbeddedProto::destroy_at(&message_.thermocoupleMessage_);
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
          case FieldNumber::BAROMETERMESSAGE:
            return_value = message_.barometerMessage_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::ACCELEROMETERMESSAGE:
            return_value = message_.accelerometerMessage_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::MAGNETOMETERMESSAGE:
            return_value = message_.magnetometerMessage_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::GYROSCOPERMESSAGE:
            return_value = message_.gyroscoperMessage_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::THERMOCOUPLEMESSAGE:
            return_value = message_.thermocoupleMessage_.deserialize_check_type(buffer, wire_type);
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
          case FieldNumber::BAROMETERMESSAGE:
            left_chars = message_.barometerMessage_.to_string(left_chars, indent_level, BAROMETERMESSAGE_NAME, first_field);
            break;
          case FieldNumber::ACCELEROMETERMESSAGE:
            left_chars = message_.accelerometerMessage_.to_string(left_chars, indent_level, ACCELEROMETERMESSAGE_NAME, first_field);
            break;
          case FieldNumber::MAGNETOMETERMESSAGE:
            left_chars = message_.magnetometerMessage_.to_string(left_chars, indent_level, MAGNETOMETERMESSAGE_NAME, first_field);
            break;
          case FieldNumber::GYROSCOPERMESSAGE:
            left_chars = message_.gyroscoperMessage_.to_string(left_chars, indent_level, GYROSCOPERMESSAGE_NAME, first_field);
            break;
          case FieldNumber::THERMOCOUPLEMESSAGE:
            left_chars = message_.thermocoupleMessage_.to_string(left_chars, indent_level, THERMOCOUPLEMESSAGE_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace Proto
#endif // SENSORDATA_H