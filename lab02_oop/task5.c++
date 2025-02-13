#include <iostream>
#include <string>

using namespace std;

class MusicPlayer
{
private:
    string playlist[100];
    string currentSong;
    int songCount;

public:
    MusicPlayer()
    {
        songCount = 0;
        currentSong = "None";
    }

    void addSong(string song)
    {
        if (songCount < 100)
        {
            playlist[songCount++] = song;
            cout << song << " added to the playlist.\n";
        }
        else
        {
            cout << "Playlist is full!\n";
        }
    }

    void removeSong(string song)
    {
        bool found = false;
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                for (int j = i; j < songCount - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                songCount--;
                found = true;
                cout << song << " removed from the playlist.\n";
                break;
            }
        }
        if (!found)
        {
            cout << "Song not found!\n";
        }
    }

    void playSong(string song)
    {
        bool found = false;
        for (int i = 0; i < songCount; i++)
        {
            if (playlist[i] == song)
            {
                currentSong = song;
                found = true;
                cout << "Now playing: " << song << "\n";
                break;
            }
        }
        if (!found)
        {
            cout << "Song not found!\n";
        }
    }

    void showPlaylist()
    {
        cout << "\nPlaylist:\n";
        for (int i = 0; i < songCount; i++)
        {
            cout << i + 1 << ". " << playlist[i] << "\n";
        }
    }
};

int main()
{
    MusicPlayer player;
    int choice;
    string song;

    do
    {
        cout << "\n1. Add Song\n2. Remove Song\n3. Play Song\n4. Show Playlist\n5. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, song);
            player.addSong(song);
            break;
        case 2:
            cout << "Enter song name: ";
            getline(cin, song);
            player.removeSong(song);
            break;
        case 3:
            cout << "Enter song name: ";
            getline(cin, song);
            player.playSong(song);
            break;
        case 4:
            player.showPlaylist();
            break;
        case 5:
            cout << "Exiting!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
