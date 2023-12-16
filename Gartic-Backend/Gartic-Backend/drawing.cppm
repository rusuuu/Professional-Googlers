#pragma once

export module drawing;

#include <string>
#include <iostream>

namespace gartic
{
    export class Drawing
    {
    public:

        // Constructors
        Drawing();
        Drawing(int id, int gameId, std::string data);

        // Rule of Five
        Drawing(const Drawing& other);
        Drawing(Drawing&& other) noexcept;
        Drawing& operator=(Drawing other);

        ~Drawing();

        // Member functions
        friend void swap(Drawing& first, Drawing& second) noexcept;
        friend std::ostream& operator<< (std::ostream& os, const Drawing& drawing);

        const int GetId() const;
        const int GetGameId() const;
        const std::string& GetData() const;

        void SetId(int id);
        void SetGameId(int gameId);
        void SetData(std::string& data);

    private:
        int m_id;
        int m_gameId;
        std::string m_data;

    };
}
