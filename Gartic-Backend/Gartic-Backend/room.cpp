#include "room.cppm"

namespace gartic
{
    // Constructors
    Room::Room() {}

    Room::Room(int id, std::string code)
        : m_id(id), m_code(std::move(code)) {}

    // Rule of Five
    Room::Room(const Room& other)
        : m_id(other.m_id), m_code(other.m_code) {}

    Room::Room(Room&& other) noexcept
        : Room()
    {
        swap(*this, other);
    }

    Room& Room::operator=(Room other)
    {
        swap(*this, other);
        return *this;
    }

    Room::~Room() {}

    // Member functions
    void swap(Room& first, Room& second) noexcept
    {
        using std::swap;
        swap(first.m_id, second.m_id);
        swap(first.m_code, second.m_code);
    }

    std::ostream& operator<< (std::ostream& os, const Room& room)
    {
        os << "Room: " << room.m_id << ", Code: " << room.m_code;
        return os;
    }


    //Getters

    const int Room::GetId() const
    {
        return m_id;
    }

    const std::string& Room::GetCode() const
    {
        return m_code;
    }

    //Setters

    void Room::SetId(int id)
    {
        m_id = id;
    }

    void Room::SetCode(const std::string& code)
    {
        m_code = code;
    }
}
