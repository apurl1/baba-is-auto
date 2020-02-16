#include <baba-is-auto/Games/Map.hpp>

#include <fstream>

namespace baba_is_auto
{
Map::Map(std::size_t width, std::size_t height)
    : m_width(width), m_height(height)
{
    m_objects.reserve(m_width * m_height);

    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        m_objects.emplace_back(ObjectType::EMPTY);
    }
}

void Map::Load(std::string_view filename)
{
    std::ifstream mapFile(filename.data());

    mapFile >> m_width >> m_height;

    int val = 0;
    for (std::size_t i = 0; i < m_width * m_height; ++i)
    {
        mapFile >> val;
        m_objects.emplace_back(static_cast<ObjectType>(val));
    }
}

void Map::Show() const
{
    for (std::size_t y = 0; y < m_height; ++y)
    {
        for (std::size_t x = 0; x < m_width; ++x)
        {
            printf("%3d ",
                   static_cast<int>(m_objects.at(y * m_width + x).GetType()));
        }

        printf("\n");
    }
}

void Map::ParseRules()
{
    for (std::size_t y = 0; y < m_height; ++y)
    {
        for (std::size_t x = 0; x < m_width; ++x)
        {
            if (IsNounType(m_objects.at(y * m_width + x).GetType()))
            {
                // ...
            }
        }
    }
}

void Map::Assign(std::size_t row, std::size_t col, ObjectType type)
{
    m_objects.at(row * m_width + col) = Object(type);
}

Object Map::At(std::size_t row, std::size_t col)
{
    return m_objects.at(row * m_width + col);
}
}  // namespace baba_is_auto