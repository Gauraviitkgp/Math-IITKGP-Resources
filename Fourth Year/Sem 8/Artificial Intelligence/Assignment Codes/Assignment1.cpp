#include <stdio.h>
#include <iostream>

using namespace std;

class Game
{
private:
    void initialize_game()
    {
        player_turn=0;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                gamestate[i][j]=0;
    }

    void print_OX(int i, int j)
    {
        if(gamestate[i][j]==0)
            cout<<" ";
        else if(gamestate[i][j]==1)
            cout<<"X";
        else if(gamestate[i][j]==2)
            cout<<"O";
    }
    void print_game()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                print_OX(i,j);
                if(j!=2)
                    cout<<"|";
            }
            cout<<endl;
            if(i!=2)
            {
                for(int i=0;i<6;i++)
                    cout<<"-";
                cout<<endl;
            }
        }
    }

    bool victory(int X,int Y, int game[3][3])
    {
        bool verbose=false;
        //Checking Diagonals
        int i=0;
        int j=0;
        int k=0;

        if(verbose)
            cout<<endl<<"I:"<<X<<" J:"<<Y<<endl;

        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i++;j++;
        }
        i=-1;j=-1;
        while(X+i<=2 && Y+j<=2 && Y+j>=0 && X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i--;j--;
        }
        if(verbose)
            cout<<"\\ K:"<<k<<endl;
        if(k==3)
            return true;

         //Checking /
        i=0;j=0;k=0;

        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0&& game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i++;j--;
        }
        i=-1;j=1;
        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i--;j++;
        }
        if(verbose)
            cout<<"/ K:"<<k<<endl;
        if(k==3)
            return true;


        //Checking |
        i=0;j=0;k=0;

        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0&& game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i++;
        }
        i=-1;j=0;
        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            i--;
        }
        if(verbose) cout<<"| K:"<<k<<endl;
        if(k==3)
            return true;

         //Checking -
        i=0;j=0;k=0;

        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            j++;
        }
        i=0;j=-1;
        while(X+i<=2 && Y+j<=2 && Y+j>=0 &&X+i>=0 && game[X+i][Y+j]==game[X][Y])
        {
            k++;
            j--;
        }
        if(verbose) cout<<"- K:"<<k<<endl;

        if(k==3)
            return true;

        return false;

    }

    bool update_game(int X,int Y)
    {
        if(gamestate[X][Y]==0)
        {
            gamestate[X][Y]=player_turn+1;
            print_game();
            if(victory(X,Y,gamestate))
            {
                return true;
                endgame=true;
            }

            player_turn=!player_turn;
            return false;
        }
        else
        {
            cout<<"Make Correct Moves -_-"<<endl;
            return false;
        }

    }


    bool check_equal(int a,int b,int i,int j,int game[3][3])
    {
        if(i+a<=2 && i+a>=0&& j+b>=0 && j+b<=2 && (game[i+a][j+b]==game[i][j]))
           return true;
        else
            return false;
    }

    bool check_empty(int a,int b,int i,int j,int game[3][3])
    {
        if(i+a<=2 && i+a>=0&& j+b>=0 && j+b<=2 && (game[i+a][j+b]==0))
           return true;
        else
            return false;
    }


    int count_2s(int i,int j,int game[3][3])
    {
        int k=0;
        int twos=0;


        // First /
        if(check_equal(1,-1,i,j,game))
            twos++;
        else if(check_equal(2,-2,i,j,game))
            twos++;
        else if(check_equal(-1,1,i,j,game))
            twos++;
        else if(check_equal(-2,2,i,j,game))
            twos++;

        // Then \

        if(check_equal(1,1,i,j,game))
            twos++;
        else if(check_equal(2,2,i,j,game))
            twos++;
        else if(check_equal(-1,-1,i,j,game))
            twos++;
        else if(check_equal(-2,-2,i,j,game))
            twos++;


        // Then |

        if(check_equal(0,1,i,j,game))
            twos++;
        else if(check_equal(0,2,i,j,game))
            twos++;
        else if(check_equal(0,-1,i,j,game))
            twos++;
        else if(check_equal(0,-2,i,j,game))
            twos++;

        // Then -

        if(check_equal(1,0,i,j,game))
            twos++;
        else if(check_equal(2,0,i,j,game))
            twos++;
        else if(check_equal(-1,0,i,j,game))
            twos++;
        else if(check_equal(-2,0,i,j,game))
            twos++;

        return twos;
    }

    void ai_move()
    {
        int Points[3][3]={0};
        int temp_game[3][3];

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                temp_game[i][j]=gamestate[i][j];

        int Best_move[2]={0,0};
        int highest_point=0;
        int point=0;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(temp_game[i][j]==0)
                {
//                    cout<<i<<" "<<j<<endl;
                    point=1;
                    temp_game[i][j]=!human_player+1;
                    int twos=count_2s(i,j,temp_game);

                    temp_game[i][j]=human_player+1;
                    int twoso=count_2s(i,j,temp_game);

                    if(twoso==1)
                        point=40;

                    if(twos==1)
                        point=50;

                    if(twos==2)
                        point=200;

                    if(twos==3)
                        point=300;

                    if(twoso==2)
                        point=400;

                    if(twoso==3)
                        point=450;

                    if(victory(i,j,temp_game))
                        point=500;

                    temp_game[i][j]=!human_player+1;
                    if(victory(i,j,temp_game))
                        point=1000;

                    Points[i][j]=point;
                    if(highest_point<point)
                    {
                        highest_point=point;
                        Best_move[0]=i;
                        Best_move[1]=j;
                    }
                    temp_game[i][j]=0;
                 }
            }

        }

        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cout<<Points[i][j]<<"\t";
        cout<<endl;
        X=Best_move[0];
        Y=Best_move[1];
    }

    void checkgameend()
    {
        endgame=true;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(gamestate[i][j]==0)
                    endgame=false;

    }

public:
    int gamestate[3][3];
    bool player_turn;
    bool human_player;
    bool another_game;
    bool endgame;
    int X,Y;

    void start_game()
    {
        another_game=false;
        endgame=false;
        cout<<"Do you want to be player 0 or 1 Please enter 0 or 1:";
        cin>>human_player;
        initialize_game();
        play_game();
    }

    void play_game()
    {

        while(1)
        {
            if(endgame==false)
                checkgameend();
            if(endgame)
            {
                cout<<"Would you like to play another game? say 1 for yes 0 for no:";
                cin>>another_game;
                break;
            }
            else if(human_player==player_turn)
            {
                cout<<"Your turn!!!"<<endl;
                cout<<"Enter X(0,1,2) and Y cordinate at position where you wish to enter your turn:";
                cin>>X>>Y;
                if(update_game(X,Y))
                {
                    cout<<"Player "<<player_turn<<" wins! Horrayy!"<<endl;
                    break;
                }
            }
            else
            {
                cout<<"Computer's turn:";
                ai_move();
                cout<<"Computer is moving at X:"<<X<<" Y:"<<Y<<endl;
                if(update_game(X,Y))
                {
                    cout<<"Player "<<player_turn<<" wins! Horrayy!"<<endl;
                    break;
                }


            }
        }

    }

};

int main()
{
    Game tictactoe;
    while(1)
    {
        tictactoe.start_game();
        if(tictactoe.another_game==false)
            break;
    }


}
