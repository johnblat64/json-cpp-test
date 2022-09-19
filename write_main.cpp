#include <iostream>
#include <vector>
#include "external/json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;


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


int
main() {

    Player p1;
    p1.x = 5.0f;
    p1.y = 15.0f;
    p1.name = "joshua";
    p1.speed = 100.0f;
    p1.animation_frames.push_back(5);
    p1.animation_frames.push_back(15);
    p1.animation_frames.push_back(115);

    json p1_json;
    to_json(p1_json, p1);

    std::cout << p1_json << "\n";


    Velocity v1;
    v1.x = 90.0f;
    v1.y = 190.0f;

    json v1_json;
    to_json(v1_json, v1);


    Entity entity1;
    entity1.player = p1;
    entity1.velocity = v1;

    json entity_json1;
    to_json(entity_json1, entity1);

    std::cout << entity_json1 << "\n";
    std::string dump_str = entity_json1.dump();
    FILE *f = fopen("dump", "w");
    fwrite(dump_str.c_str(), sizeof(char), dump_str.length(), f);
    fclose(f);
    return 0;
}
