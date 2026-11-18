//---------------------------------------------------------
// Music Streamer
// Challenge 2 - Programming Skills Portfolio
//---------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


//---------------------------------------------------------
// Main Program
//---------------------------------------------------------
// Controls the overall execution of the Music Streamer.
// The main program loads songs from a text file,
// prepares the program for use and provides access
// to the menu system and song playback features.
int main()
{
    //-----------------------------------------------------
    // Variable Declaration Section
    //-----------------------------------------------------
    // Creates the vectors used to store available songs
    // and songs that have already been played. A string
    // variable is also used to temporarily store each
    // song title when it is read from the file.
    vector<string> songs; 
    vector<string> playedSongs; 
    string song; 

    //-----------------------------------------------------
    // Load Songs From File
    //-----------------------------------------------------
    // Opens the songs.txt file and loads each song title
    // into the songs vector. Using a vector allows the
    // program to store a dynamic collection of songs
    // which can later be randomly selected for playback.
    ifstream file("songs.txt"); 

    // Checks whether the file has opened successfully.
    // If the file cannot be found or accessed, an error
    // message is displayed and the program exits safely.
    if (!file)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Reads each song title from the file and stores it
    // within the songs vector for use during playback.
    while (getline(file, song))
    {
        songs.push_back(song);
    }
    // Closes the file after all songs have been
    // successfully loaded into memory.
    file.close();

//-----------------------------------------------------
// Program Setup Section
//-----------------------------------------------------
// PURPOSE:
// Prepares the application before the user can interact
// with the system.
//
// IMPLEMENTATION:
// Confirms songs were successfully loaded from the file.
// Initialises the random number generator.
// Creates variables required for menu operation.
//
// DESIGN DECISIONS:
// A vector is used to store songs because it allows
// dynamic storage and easy access using indexes.
// Randomisation was included to simulate a music
// streaming service and provide a different user
// experience during each execution.
//
// TESTING CONSIDERATION:
// The loaded song count is displayed to verify that
// songs.txt was opened and processed correctly.
//-----------------------------------------------------
    cout << songs.size() 
        << " songs loaded successfully.\n" 
        << endl;
    // Seeds the random number generator using the
    // current system time to improve randomness.
    srand(time(0)); 
    // Stores the user's selected menu option.
    int choice;

    //-----------------------------------------------------
    // Menu System Section
    //-----------------------------------------------------
    // Displays the main menu and allows the user to
    // interact with the Music Streamer. A do-while
    // loop is used so the menu continues running
    // until the user chooses to quit the program.
    do
    {
        cout << "===== MUSIC STREAMER =====" << endl;
        cout << "1. Play Random Song" << endl;
        cout << "2. Songs Remaining" << endl;
        cout << "3. Songs Already Played" << endl;
        cout << "4. Quit" << endl;
        cout << "Select Option: ";
        // Stores the user's selected menu option.
        cin >> choice;

        //-------------------------------------------------
        // Menu Processing Section
        //-------------------------------------------------
        // Uses a switch statement to process the user's
        // selected menu option and run the corresponding
        // music streamer functionality.
        switch (choice)
        {
        case 1:

    //-------------------------------------------------
    // Random Song Selection Section
    //-------------------------------------------------
    // PURPOSE:
    // Simulate the behaviour of a music streaming service
    // by selecting songs unpredictably rather than in a
    // fixed order.
    //
    // DESIGN DECISION:
    // rand() was chosen to generate a random vector index.
    // This allows different songs to be selected during
    // each execution, creating a more realistic user
    // experience compared to sequential playback.
    //
    // USER BENEFIT:
    // Users experience variety because songs are not
    // played in the same order every time the program
    // is run.
    //
    // TESTING:
    // Verify songs are selected from different positions
    // in the vector and do not repeat until all songs
    // have been played.
    //-------------------------------------------------
        if (songs.empty())
        {
            cout << "\nAll songs have been played.\n" << endl;
            break;
        }

        int randomIndex;
        randomIndex = rand() % songs.size();
            // Generates a random valid position within the songs
            // vector, allowing any remaining song to be selected.

        cout << "\nNow Playing: "
            << songs[randomIndex]
            << "\n" << endl;

        //-------------------------------------------------
        // Played Song Tracking Section
        //-------------------------------------------------
    // PURPOSE:
    // Ensure songs cannot repeat until every available
    // song has been played at least once.
    //
    // IMPLEMENTATION:
    // The selected song is copied into the playedSongs
    // vector and then removed from the active songs
    // vector.
    //
    // WHY THIS APPROACH:
    // Separating played songs from available songs
    // guarantees that future random selections can only
    // choose from unplayed songs.
    //
    // BENEFIT:
    // Creates a more realistic music streaming experience
    // and prevents users hearing the same song repeatedly
    // before the playlist is exhausted.
    //
    // CHALLENGE SOLVED:
    // Preventing duplicate playback while still using
    // random song selection.
    //-------------------------------------------------
        playedSongs.push_back(songs[randomIndex]);
        songs.erase(songs.begin() + randomIndex);

        break;

        case 2:

        //-------------------------------------------------
        // Songs Remaining Section
        //-------------------------------------------------
        // Displays the number of songs that are still
        // available within the songs vector and can
        // be selected for playback.
        cout << "\nSongs Remaining: "
            << songs.size()
            // Displays the total number of songs loaded into the
            // vector. This confirms that file handling was successful
            // and provides a simple way to verify that data from
            // songs.txt was stored correctly before the program starts.
            << "\n" << endl;

        break;

        case 3:

        //-------------------------------------------------
        // Display Played Songs Section
        //-------------------------------------------------
        // Displays all songs currently stored within the
        // playedSongs vector. A for-each loop is used to
        // iterate through the collection and output each
        // song that has already been played during the
        // current session.
        cout << "\nPlayed Songs\n" << endl;

        for (string song : playedSongs)
        {
            cout << song << endl;
        }

        cout << endl;

        break;

        case 4:

        //-------------------------------------------------
        // Exit Program Section
        //-------------------------------------------------
        // Ends the Music Streamer when the user selects
        // the quit option. A closing message is displayed
        // before the program terminates.
        cout << "\nGoodbye!" << endl;
        break;

        default:

        //-------------------------------------------------
        // Invalid Menu Option Section
        //-------------------------------------------------
        // Handles invalid menu selections by displaying
        // an error message when the entered option does
        // not exist within the menu system.
        cout << "\nInvalid Option\n" << endl;
        }

        //-------------------------------------------------
        // Menu Processing Section End
        //-------------------------------------------------
        }   while (choice != 4);
//---------------------------------------------------------
// End Main Program
//---------------------------------------------------------
    return 0;
}

//76 lines of exacutiable code with no spaces and comments 
//with 220 word count 
