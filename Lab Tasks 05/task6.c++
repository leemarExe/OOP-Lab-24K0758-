#include<iostream>
#include<string>
using namespace std;

class Level{
    string level_name;
    string level_difficulty;
    public:
    Level(){}
    Level(string n, string d){
        level_name = n;
        level_difficulty = d;
    }
    string get_level_name()const{
        return level_name;
    }
    string get_level_difficulty()const{
        return level_difficulty;
    }

};

class Game{
    string game_name, genre;
    Level* levels;
    int levelCount;
    int maxLevels;
    public:
    Game(string n, string g, int l){
        game_name = n;
        genre = g;
        levelCount = 0;
        maxLevels = l;
        levels = new Level[l];
    }
    ~Game(){
        delete[] levels;
    }
    void addLevel(string name, string difficulty){
        if(levelCount < 5){
            levels[levelCount] = Level(name, difficulty);
            levelCount += 1;
            cout<<"Level ("<<name<<") added to the Game.\n";
        }
        else{
            cout<<"There are 5 levels already.\n";
        }
    }
    void gameInfo(){
        cout<<"Game Name: " <<game_name<< endl;
        cout<<"Game Genre: " <<genre<<endl;
        if(levelCount == 0){
            cout<<"No levels added yet.\n";
            return;
        }
        cout<<"Current Levels: \n";
        for(int i = 0 ; i < levelCount ; i++){
            cout<<"Level Name: "<<levels[i].get_level_name()<<endl;
            cout<<"Level Difficulty: "<<levels[i].get_level_difficulty()<<endl;
        }
    }


};


int main(){
    Game myGame("Cyber Quest", "Action RPG", 3);

    myGame.addLevel("Forest of Shadows", "Hard");
    myGame.addLevel("Desert Ruins", "Medium");
    myGame.addLevel("Sky Fortress", "Hard");


    myGame.gameInfo();

    return 0;
}