//
// Created by frog on 9/18/22.
//
#include <iostream>
#include <vector>
#include "external/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;
#include <stdio.h>
#include <string>


struct Player
{
    int x, y;
    std::string name;
    float speed;
    std::vector<unsigned int> animation_frames;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Player, x, y, speed, animation_frames)
};



struct Velocity
{
    float x, y;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Velocity, x, y)
};


struct Entity
{
    Player player;
    Velocity velocity;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Entity, player, velocity)
};


int main()
{
    FILE *f = fopen("dump", "r");
    std::string json_str;
    fseek(f, 0, SEEK_END);
    size_t file_size = ftell(f);
    json_str.resize(file_size);
    rewind(f);
    fread(&json_str[0], sizeof(char), file_size, f);
    fclose(f);

    json json1 = json::parse(json_str);

    Entity e1;
    from_json(json1, e1);

    // RUN IN DEBUGGER TO VERIFY e1 MEMBERS

    return 0;
}