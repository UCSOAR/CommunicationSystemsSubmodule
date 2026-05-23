/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: CommandMessages.proto
 */

// This file is generated. Please do not edit!
#ifndef COMMANDMESSAGES_H
#define COMMANDMESSAGES_H

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

class FsbCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    FsbCommand() = default;
    FsbCommand(const FsbCommand& rhs )
    {
      set_fsb_message(rhs.get_fsb_message());
    }

    FsbCommand(const FsbCommand&& rhs ) noexcept
    {
      set_fsb_message(rhs.get_fsb_message());
    }

    ~FsbCommand() override = default;

    enum class Command : uint32_t
    {
      START_LOGGING = 0,
      STOP_LOGGING = 1,
      SEND_FILES = 2
    };

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      FSB_MESSAGE = 1
    };

    FsbCommand& operator=(const FsbCommand& rhs)
    {
      set_fsb_message(rhs.get_fsb_message());
      return *this;
    }

    FsbCommand& operator=(const FsbCommand&& rhs) noexcept
    {
      set_fsb_message(rhs.get_fsb_message());
      return *this;
    }

    static constexpr char const* FSB_MESSAGE_NAME = "fsb_message";
    inline void clear_fsb_message() { fsb_message_.clear(); }
    inline void set_fsb_message(const Command& value) { fsb_message_ = value; }
    inline void set_fsb_message(const Command&& value) { fsb_message_ = value; }
    inline const Command& get_fsb_message() const { return fsb_message_.get(); }
    inline Command fsb_message() const { return fsb_message_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<Command>(0) != fsb_message_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = fsb_message_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FSB_MESSAGE), buffer, false);
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
          case FieldNumber::FSB_MESSAGE:
            return_value = fsb_message_.deserialize_check_type(buffer, wire_type);
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
      clear_fsb_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::FSB_MESSAGE:
          name = FSB_MESSAGE_NAME;
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

      left_chars = fsb_message_.to_string(left_chars, indent_level + 2, FSB_MESSAGE_NAME, true);
  
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


      EmbeddedProto::enumeration<Command> fsb_message_ = static_cast<Command>(0);

};

class CommandMessages final: public ::EmbeddedProto::MessageInterface
{
  public:
    CommandMessages() = default;
    CommandMessages(const CommandMessages& rhs )
    {
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        default:
          break;
      }

    }

    CommandMessages(const CommandMessages&& rhs ) noexcept
    {
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        default:
          break;
      }

    }

    ~CommandMessages() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SOURCE_SEQUENCE_NUM = 1,
      FSB_COMMAND = 2
    };

    CommandMessages& operator=(const CommandMessages& rhs)
    {
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        default:
          break;
      }

      return *this;
    }

    CommandMessages& operator=(const CommandMessages&& rhs) noexcept
    {
      set_source_sequence_num(rhs.get_source_sequence_num());
      if(rhs.get_which_message() != which_message_)
      {
        // First delete the old object in the oneof.
        clear_message();
      }

      switch(rhs.get_which_message())
      {
        case FieldNumber::FSB_COMMAND:
          set_fsb_command(rhs.get_fsb_command());
          break;

        default:
          break;
      }

      return *this;
    }

    static constexpr char const* SOURCE_SEQUENCE_NUM_NAME = "source_sequence_num";
    inline void clear_source_sequence_num() { source_sequence_num_.clear(); }
    inline void set_source_sequence_num(const uint32_t& value) { source_sequence_num_ = value; }
    inline void set_source_sequence_num(const uint32_t&& value) { source_sequence_num_ = value; }
    inline uint32_t& mutable_source_sequence_num() { return source_sequence_num_.get(); }
    inline const uint32_t& get_source_sequence_num() const { return source_sequence_num_.get(); }
    inline uint32_t source_sequence_num() const { return source_sequence_num_.get(); }

    FieldNumber get_which_message() const { return which_message_; }

    static constexpr char const* FSB_COMMAND_NAME = "fsb_command";
    inline bool has_fsb_command() const
    {
      return FieldNumber::FSB_COMMAND == which_message_;
    }
    inline void clear_fsb_command()
    {
      if(FieldNumber::FSB_COMMAND == which_message_)
      {
        which_message_ = FieldNumber::NOT_SET;
        message_.fsb_command_.~FsbCommand();
      }
    }
    inline void set_fsb_command(const FsbCommand& value)
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      message_.fsb_command_ = value;
    }
    inline void set_fsb_command(const FsbCommand&& value)
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      message_.fsb_command_ = value;
    }
    inline FsbCommand& mutable_fsb_command()
    {
      if(FieldNumber::FSB_COMMAND != which_message_)
      {
        init_message(FieldNumber::FSB_COMMAND);
      }
      return message_.fsb_command_;
    }
    inline const FsbCommand& get_fsb_command() const { return message_.fsb_command_; }
    inline const FsbCommand& fsb_command() const { return message_.fsb_command_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != source_sequence_num_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = source_sequence_num_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOURCE_SEQUENCE_NUM), buffer, false);
      }

      switch(which_message_)
      {
        case FieldNumber::FSB_COMMAND:
          if(has_fsb_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = message_.fsb_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FSB_COMMAND), buffer, true);
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
          case FieldNumber::SOURCE_SEQUENCE_NUM:
            return_value = source_sequence_num_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FSB_COMMAND:
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
      clear_source_sequence_num();
      clear_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SOURCE_SEQUENCE_NUM:
          name = SOURCE_SEQUENCE_NUM_NAME;
          break;
        case FieldNumber::FSB_COMMAND:
          name = FSB_COMMAND_NAME;
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

      left_chars = source_sequence_num_.to_string(left_chars, indent_level + 2, SOURCE_SEQUENCE_NUM_NAME, true);
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


      EmbeddedProto::uint32 source_sequence_num_ = 0U;

      FieldNumber which_message_ = FieldNumber::NOT_SET;
      union message
      {
        message() {}
        ~message() {}
        FsbCommand fsb_command_;
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
          case FieldNumber::FSB_COMMAND:
            new(&message_.fsb_command_) FsbCommand;
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
          case FieldNumber::FSB_COMMAND:
            ::EmbeddedProto::destroy_at(&message_.fsb_command_);
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
          case FieldNumber::FSB_COMMAND:
            return_value = message_.fsb_command_.deserialize_check_type(buffer, wire_type);
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
          case FieldNumber::FSB_COMMAND:
            left_chars = message_.fsb_command_.to_string(left_chars, indent_level, FSB_COMMAND_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace Proto
#endif // COMMANDMESSAGES_H