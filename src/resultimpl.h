/**
 *  ResultImpl.h
 *
 *  Base class for result implementation
 *
 *  @copyright 2014 Copernica BV
 */

/**
 *  Set up namespace
 */
namespace React { namespace MySQL {

// forward declaration
class ResultRowImpl;

/**
 *  Result implementation
 */
class ResultImpl
{
public:
    /**
     *  Get the fields and their index
     */
    virtual const std::map<std::string, size_t>& fields() const = 0;

    /**
     *  Get the number of rows in this result set
     */
    virtual size_t size() const = 0;

    /**
     *  Retrieve row at the given index
     */
    virtual const std::vector<std::unique_ptr<ResultFieldImpl>>& fetch(size_t index) = 0;
};

/**
 *  End namespace
 */
}}
