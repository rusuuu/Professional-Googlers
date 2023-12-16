#pragma once

export module room;

#include <string>
#include <iostream>

namespace gartic
{
    export class Room
    {
    public:

        // Constructors
        Room();
        Room(int id, std::string code);

        // Rule of Five
        Room(const Room& other);
        Room(Room&& other) noexcept;
        Room& operator=(Room other);

        ~Room();

        // Member functions
        friend void swap(Room& first, Room& second) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const Room& room);

        const int GetId() const;
        const std::string& GetCode() const;

        void SetId(int id);
        void SetCode(const std::string& code);

    private:
        int m_id;
        std::string m_code;
    };
}
