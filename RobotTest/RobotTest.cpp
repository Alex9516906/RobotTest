
#include <iostream>
#include<vector>
using namespace std;


class OffTheField
{
public:
    string m_error = " Off the Field";
};

class IllegalCommand
{
public:
    string m_error = " IllegalCommand";
};



class Robot
{
private:
    int size = 10;
    vector<vector<char>> Pole;
    const char empty1 = '-';
    const char robot = 'R';
    int posRobotTop = 0;
    int posRobotRight = 0;
public:
    Robot()
    {
        Pole.resize(size,vector<char>(size));
        for (size_t i = 0; i < size; i++) // создаем поле
        {
            
            for (size_t j = 0; j < size; j++)
            {
                Pole[i][j]=empty1;
            }
        }
        Pole[0][0] = robot;
        SetPosRobot(0, 0);
    }
    void SetPosRobot(int top, int right)
    {
        posRobotTop = top;
        posRobotRight = right;
    }

    void Move(const string &a)
    {
        if (a == "left" || a == "LEFT" || a == "Left")
        {
            if (posRobotRight - 1 < 0)
            {
                throw OffTheField();
            }
            Pole[posRobotTop][posRobotRight] = empty1;
            Pole[posRobotTop][posRobotRight - 1] = robot;
            SetPosRobot(posRobotTop, (posRobotRight - 1));
            print();
        }
        else if (a == "right" || a == "RIGHT" || a == "Right")
        {
            if (posRobotRight + 1 > size)
            {
                throw OffTheField();
            }
            Pole[posRobotTop][posRobotRight] = empty1;
            Pole[posRobotTop][posRobotRight + 1] = robot;
            SetPosRobot(posRobotTop, (posRobotRight + 1));
            print();
        }
        else if (a == "Top" || a == "top" || a == "TOP")
        {
            if (posRobotTop - 1 < 0)
            {
                throw OffTheField();
            }
            Pole[posRobotTop][posRobotRight] = empty1;
            Pole[posRobotTop - 1][posRobotRight] = robot;
            SetPosRobot(posRobotTop - 1, posRobotRight);
            print();
        }
        else if (a == "down" || a == "Down" || a == "DOWN")
        {
            if (posRobotTop + 1 > size)
            {
                throw OffTheField();
            }
            Pole[posRobotTop][posRobotRight] = empty1;
            Pole[posRobotTop + 1][posRobotRight] = robot;
            SetPosRobot(posRobotTop + 1, posRobotRight);
            print();
        }
        else
            throw IllegalCommand();
    }
    
    void print()
    {
        cout << endl;
        for (int i = 0; i < size; i++) // создаем поле
        {
            
            for (int j = 0; j < size; j++)
            {
                cout << Pole[i][j] << " ";
            }
            cout << endl;
        }

    }
};
int main()
{
    string command;
    Robot robo;
    robo.print();
    while (true){
        try
        {
        cout << "Enter the command" << endl;;
        cin >> command;
        robo.Move(command);  
        }
        catch (IllegalCommand& err)
        {
            std::cerr << "Error :" << err.m_error << std::endl;
        }
        catch (OffTheField& err)
        {
            std::cerr << "Error :" << err.m_error << std::endl;
        }
    }


}
