#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

// vector<vector<int>> matrix(rows, vector<int>(col, 0));
const int RANKS = 7; // rows
const int FILES = 7; // columns
vector<vector<string>> board(RANKS, vector<string>(FILES, "x"));

void printBoard()
{
    // cout << "Printing the board" << endl;
    for (int r = 0; r < RANKS; r++)
    {
        for (int c = 0; c < FILES; c++)
        {
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
} // end printBoard

/*
function to split a string with a given delimiter
returns resulting list of tokens
*/
vector<string> split(string str, char del)
{
    vector<string> res;
    string temp;

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] != del)
        {
            temp = temp + str[i];
        }
        else
        {
            // add current temp to vector and reset it
            res.push_back(temp);
            temp = ""; // reset temp
            // continue;
        }
    } // end for

    res.push_back(temp);
    return res;
} // end split function


//my version of strcmp to compare strings instead if chars
int compare (string a, string b){
    if(a < b){
        return -1;
    }
    if (b < a){
        return 1;
    }
    return 0;

}//end compare

string bubbleSort(vector<string> arr)
{
    int n = arr.size();
    string result;

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {

            if (compare(arr[j+1], arr[j]) < 0) // ie b is on the wrong side a
            {
                // swap
                string temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }

        } // end for j
    }     // end for i

    for(int k = 0; k < n; k++){
        result = result + " " + arr[k];
    }
    return result;
}

// taking in a fen string, represent the current board state
void configureBoard(vector<string> fen)
{
    // white pices
    string Pawn, Superpawn, Giraffe, Monkey, Elephant, Lion, Croc, Zebra;
    // black pieces
    string pawn, superpawn, giraffe, monkey, elephant, lion, croc, zebra;

    vector<string> posOfPieces;
    posOfPieces.reserve(7); // idk if this is really necessary

    posOfPieces = split(fen[0], '/');
    string sideToMove;
    string moveNum = fen[2]; //remember to convert this to integer

    if (fen[1] == "b")
    {
        sideToMove = "black";
    }
    else
    {
        sideToMove = "white";
    }

    // loop through positions vector -- each index represents a rank
    for (int i = 0; i < posOfPieces.size(); i++)
    {
        int rank = 7 - i;
        /*
        cout << endl
             << endl
             << "rank number: " << rank << endl;
        cout << "curr: " << posOfPieces[i] << endl;*/
        int fileCount = 0;
        string curr = posOfPieces[i];
        string fileName = "abcdefg";

        // loop through ever char in curr
        for (int j = 0; j < curr.length(); j++)
        {
            // cout << "Current token that we're dealing with: " << curr << endl;
            // check if the char is a digit
            char ch = curr[j];

            //cout << "ch: " << ch << endl;

            if (isdigit(ch))
            {
                // dealing with spaces
                int num = (int)ch - 48;
                //cout << "there are " << num << " BLANK SPACES" << endl;
                if (num != 7 || (fileCount + num) < 7)
                {
                    // cater for blank spaces in the fileCount and fileName, else do nothing
                    fileCount = fileCount + num;
                }
                else
                {
                    //cout << "(this is a blank rank)" << endl;
                }
            } // end if isdigit
            else
            {
                // this is a board piece
                //cout << "this is a ";

                if (ch == 'p')
                {
                    //cout << "black pawn" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    pawn = pawn + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'P')
                {
                    //cout << "white pawn" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Pawn = Pawn + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 's')
                {
                    //cout << "black super pawn" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    superpawn = superpawn + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'S')
                {
                    //cout << "white super pawn" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Superpawn = Superpawn + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'g')
                {
                    //cout << "black giraffe" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    giraffe = giraffe + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'G')
                {
                    //cout << "white giraffe" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Giraffe = Giraffe + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'm')
                {
                    //cout << "black monkey" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    monkey = monkey + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'M')
                {
                    //cout << "white monkey" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Monkey = Monkey + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'e')
                {
                    //cout << "black elephant" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    elephant = elephant + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'E')
                {
                    //cout << "white elephant" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Elephant = Elephant + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'l')
                {
                    //cout << "black lion" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    lion = lion + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'L')
                {
                    //cout << "white lion" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Lion = Lion + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'c')
                {
                    //cout << "black croc" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    croc = croc + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'C')
                {
                    //cout << "white croc" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Croc = Croc + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'z')
                {
                    //cout << "black zebra" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    zebra = zebra + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }
                if (ch == 'Z')
                {
                    //cout << "white zebra" << endl;
                    //cout << "square: " << fileName[fileCount] << rank << endl;
                    Zebra = Zebra + "/" + fileName[fileCount] + to_string(rank);
                    fileCount++;
                }

            } // end else

        } // end for loop columns
    }     // end for loop ranks

    // sort all the squares in alphabetical order


    // cout << "Side to Move: " << sideToMove << endl;
    // cout << "Move Number: " << moveNum << endl;
    //cout << "---------------------------------------------------------------------------------------------------" << endl;
    vector<string> temp = split(Pawn, '/');
    Pawn = bubbleSort(temp);
    cout << "white pawn:" << Pawn << endl;

    temp = split(pawn, '/');
    pawn = bubbleSort(temp);
    cout << "black pawn:" << pawn << endl;

    temp = split(Superpawn, '/');
    Superpawn = bubbleSort(temp);
    cout << "white superpawn:" << Superpawn << endl;

    temp = split(superpawn, '/');
    superpawn = bubbleSort(temp);
    cout << "black superpawn:" << superpawn << endl;

    temp = split(Giraffe, '/');
    Giraffe = bubbleSort(temp);
    cout << "white giraffe:" << Giraffe << endl;

    temp = split(giraffe, '/');
    giraffe = bubbleSort(temp);
    cout << "black giraffe:" << giraffe << endl;

    temp = split(Monkey, '/');
    Monkey = bubbleSort(temp);
    cout << "white monkey:" << Monkey << endl;

    temp = split(monkey, '/');
    monkey = bubbleSort(temp);
    cout << "black monkey:" << monkey << endl;

    temp = split(Elephant, '/');
    Elephant = bubbleSort(temp);
    cout << "white elephant:" << Elephant << endl;

    temp = split(elephant, '/');
    elephant = bubbleSort(temp);
    cout << "black elephant:" << elephant << endl;

    temp = split(Lion, '/');
    Lion = bubbleSort(temp);
    cout << "white lion:" << Lion << endl;

    temp = split(lion, '/');
    lion = bubbleSort(temp);
    cout << "black lion:" << lion << endl;

    temp = split(Croc, '/');
    Croc = bubbleSort(temp);
    cout << "white crocodile:" << Croc << endl;

    temp = split(croc, '/');
    croc = bubbleSort(temp);
    cout << "black crocodile:" << croc << endl;

    temp = split(Zebra, '/');
    Zebra = bubbleSort(temp);
    cout << "white zebra:" << Zebra << endl;

    temp = split(zebra, '/');
    zebra = bubbleSort(temp);
    cout << "black zebra:" << zebra << endl;

    cout << "side to play: "<< sideToMove << endl;


} // end configureBoard

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<string> forsythFields;

    //cout << "compare a1 then b1: "<< compare("a1", "b6") << endl; //-1
    //cout << "compare b1 then a1: " << compare("b6", "a1") << endl; // 1
    //cout << "compare b1 then b1: " << compare("b6", "b6") << endl; // 0

    for (int i = 0; i < N; i++)
    {
        string fen;
        getline(cin, fen);
        forsythFields = split(fen, ' '); // split by space for fields: position of pieces/sidetomove/movenum

        // get configuration for this fen string
        configureBoard(forsythFields);

    } // end for

    // printBoard();

    return 0;
}