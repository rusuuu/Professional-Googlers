#include "drawing.cppm"

namespace gartic
{
    // Constructors
    Drawing::Drawing() {}

    Drawing::Drawing(int id, int gameId, std::string data)
		: m_id(id), m_gameId(gameId), m_data(std::move(data)){}

    // Rule of Five
    Drawing::Drawing(const Drawing& other)
        : m_id(other.m_id), m_gameId(other.m_gameId), m_data(other.m_data){}

    Drawing::Drawing(Drawing&& other) noexcept
        : Drawing()
    {
        swap(*this, other);
    }

    Drawing& Drawing::operator=(Drawing other)
    {
        swap(*this, other);
        return *this;
    }

    Drawing::~Drawing() {}

    // Member functions
    void swap(Drawing& first, Drawing& second) noexcept
    {
        using std::swap;
        swap(first.m_id, second.m_id);
        swap(first.m_gameId, second.m_gameId);
        swap(first.m_data, second.m_data);
        
    }

    std::ostream& operator<< (std::ostream& os, const Drawing& drawing)
    {
        os << "Drawing: " << drawing.m_id << ", Game Id: " << drawing.m_gameId << ", Data: " << drawing.m_data;
        return os;
    }


    //Getters

    const int Drawing::GetId() const
    {
        return m_id;
    }

    const int Drawing::GetGameId() const
    {
        return m_gameId;
    }

    const std::string& Drawing::GetData() const
    {
        return m_data;
    }

    //Setters

    void Drawing::SetId(int id)
    {
        m_id = id;
    }

    void Drawing::SetGameId(int gameId)
    {
        m_gameId = gameId;
    }

    void Drawing::SetData(std::string& data)
    {
        m_data = data;
    }
}
