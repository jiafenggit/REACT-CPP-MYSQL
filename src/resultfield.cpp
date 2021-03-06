/**
 *  ResultField.cpp
 *
 *  A single field from a single row from
 *  a MySQL result set
 *
 *  @copyright 2014 Copernica BV
 */

#include "includes.h"

/**
 *  Set up namespace
 */
namespace React { namespace MySQL {

/**
 *  Constructor
 *
 *  @param  result  the result implementation
 *  @param  field   the field implementation
 */
ResultField::ResultField(std::shared_ptr<ResultImpl> result, ResultFieldImpl *field) :
    _result(result),
    _field(field)
{}

/**
 *  Get whether the field is NULL
 */
bool ResultField::isNULL() const
{
    // let the field handle this
    return _field == nullptr || _field->isNULL();
}

/**
 *  Cast to a number
 *
 *  Note that if the value is NULL, this will yield 0.
 *  To check for NULL values, use the isNULL function.
 *
 *  @throws std::invalid_argument   if this field does not contain a number
 *  @throws std::out_of_range       if the value is too small or too big to fit in the requested type
 */
ResultField::operator int8_t()   const { return *_field; }
ResultField::operator uint16_t() const { return *_field; }
ResultField::operator int16_t()  const { return *_field; }
ResultField::operator uint32_t() const { return *_field; }
ResultField::operator int32_t()  const { return *_field; }
ResultField::operator uint64_t() const { return *_field; }
ResultField::operator int64_t()  const { return *_field; }
ResultField::operator float()    const { return *_field; }
ResultField::operator double()   const { return *_field; }

/**
 *  Cast to a uint128_t, this assumes a binary(16) field network byte ordering
 *
 *  @throws std::out_of_range      if the value is not the correct size (16 bytes)
 */
ResultField::operator uint128_t() const { return *_field; }

/**
 *  Cast to a string
 *
 *  Note that if the value is NULL, this will yield
 *  an empty string. To check for NULL values, use
 *  the isNULL function.
 */
ResultField::operator std::string() const
{
    // let the field handle this
    return *_field;
}

/**
 *  Cast to a time structure
 *
 *  Note that if the value is NULL, or if it is not
 *  a date type, this function will return an std::tm
 *  structure set at its epoch (1900-01-01 00:00:00).
 */
ResultField::operator std::tm() const
{
    // let the field handle this
    return *_field;
}

/**
 *  Write the field to a stream
 *
 *  @param  stream  output stream to write to
 *  @param  field   the field to write
 */
std::ostream& operator<<(std::ostream& stream, const ResultField& field)
{
    // is this field NULL?
    if (field.isNULL()) return stream << "(NULL)";

    // write the string value
    else return stream << (std::string) field;
}

/**
 *  End namespace
 */
}}
