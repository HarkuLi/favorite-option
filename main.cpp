#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void talk_option(int cha);  //cha = 0: 艾樂莉絲, 1: 艾希, 2: 戴伊, 3: 寇爾
void readFile();
void writeFile();
string option_name(int opt);

int index[4];
const int airi_su[100] = {0,
                          1, 3, 4, 3, 1, 2, 1, 1, 2, 1,
                          2, 5, 2, 2, 4, 6, 2, 5, 1, 2,
                          6, 5, 6, 6, 4, 2, 4, 3, 5, 5,
                          1, 1, 1, 2, 2, 2, 1, 4, 1, 1,
                          4, 3, 3, 2, 4, 3, 4, 4, 1, 4,
                          2, 1, 1, 2, 2, 6, 6, 1, 2, 4,
                          3, 5, 2, 2, 4, 1, 2, 1, 1, 1,
                          3, 2, 2, 3, 2, 1, 2, 1, 2, 5,
                          1, 2, 4, 1, 5, 3, 2, 2, 4, 4,
                          1, 2, 4, 1, 1, 6, 4, 4, 1};

const int erushii[100] = {0,
                          4, 3, 5, 6, 5, 3, 6, 6, 3, 1,
                          2, 3, 6, 3, 2, 3, 1, 4, 3, 3,
                          3, 6, 3, 4, 3, 6, 1, 5, 3, 3,
                          3, 6, 4, 6, 2, 6, 3, 4, 1, 2,
                          3, 3, 1, 6, 4, 6, 4, 3, 3, 6,
                          3, 2, 6, 3, 1, 3, 3, 3, 5, 6,
                          3, 3, 1, 2, 6, 6, 3, 3, 3, 5,
                          3, 2, 4, 3, 5, 3, 5, 6, 1, 3,
                          3, 6, 2, 3, 3, 5, 6, 1, 1, 5,
                          5, 5, 5, 6, 3, 3, 1, 4, 1};

const int dai[100]     = {0,
                          3, 6, 3, 5, 2, 3, 3, 3, 3, 4,
                          3, 2, 3, 6, 1, 6, 5, 3, 3, 4,
                          5, 3, 3, 5, 5, 4, 5, 3, 4, 1,
                          6, 3, 4, 3, 5, 5, 4, 3, 5, 2,
                          3, 5, 3, 6, 1, 6, 3, 6, 3, 5,
                          4, 5, 5, 3, 5, 2, 2, 3, 3, 3,
                          3, 3, 5, 2, 4, 5, 3, 5, 3, 5,
                          3, 2, 3, 1, 4, 3, 2, 3, 5, 3,
                          1, 6, 2, 6, 5, 1, 5, 6, 5, 1,
                          5, 4, 3, 5, 4, 6, 5, 6, 5};

const int kaoru[100]   = {0,
                          3, 3, 2, 4, 3, 6, 2, 4, 6, 4,
                          1, 1, 5, 6, 4, 5, 6, 1, 1, 1,
                          5, 6, 1, 5, 3, 1, 5, 2, 6, 1,
                          1, 3, 6, 1, 5, 1, 2, 2, 2, 3,
                          2, 6, 5, 4, 2, 3, 5, 6, 3, 6,
                          4, 1, 3, 5, 4, 4, 4, 5, 5, 3,
                          3, 2, 5, 2, 1, 2, 4, 6, 5, 2,
                          3, 5, 6, 2, 1, 1, 4, 1, 1, 5,
                          4, 4, 2, 5, 4, 6, 1, 5, 6, 4,
                          6, 5, 6, 2, 1, 4, 2, 6, 5};

int main()
{
    int option = 0;
    int choose = 1;

    while(choose)
    {
        readFile();
        cout << "選擇團員 (1)艾樂莉絲 (2)艾希 (3)戴伊 (4)寇爾 (0)離開: ";
        cin >> option;
    
        switch(option)
        {
            case 0:
                choose = 0;
                break;
            case 1:
                talk_option(0);
                break;
            case 2:
                talk_option(1);
                break;
            case 3:
                talk_option(2);
                break;
            case 4:
                talk_option(3);
                break;
            default:
                cout << "輸入錯誤" << endl;
                break;
        }
    }

    system("CLS");    //clear the screen
    cout << "作者: 台服愛麗莎伺服器 風車妖精" << endl;
    system("pause");
    return 0;
}

void talk_option(int cha)
{
    char check;
    int whileFlag = 1;
    const int* table_ptr;
    bool flag_99 = 0;

    switch(cha)
    {
        case 0:
            table_ptr = airi_su;
            break;
        case 1:
            table_ptr = erushii;
            break;
        case 2:
            table_ptr = dai;
            break;
        case 3:
            table_ptr = kaoru;
            break;
        default:
            break;
    }

    system("CLS");    //clear the screen

    if(index[cha]>=1 && index[cha]<=97)
    {
        switch(index[cha])
        {
            case 96:
                for(int i=0; i<2; i++)
                {
                    cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                    cout << "--------------------" << endl;
                    index[cha]++;
                }

                cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                whileFlag = 1;
                while(whileFlag)
                {
                    cout << "此選項正確還是錯誤?(Y/N) ";
                    cin >> check;
                    switch (check)
                    {
                        case 'Y':
                            cout << "下次對話從2開始" << endl;
                            index[cha] = 2;
                            whileFlag = 0;
                            break;
                        case 'y':
                            cout << "下次對話從2開始" << endl;
                            index[cha] = 2;
                            whileFlag = 0;
                            break;
                        case 'N':
                            cout << "下次對話從1開始" << endl;
                            index[cha] = 1;
                            whileFlag = 0;
                            break;
                        case 'n':
                            cout << "下次對話從1開始" << endl;
                            index[cha] = 1;
                            whileFlag = 0;
                            break;
                        default:
                            break;
                    }
                }
                cout << "--------------------" << endl;
                break;
            case 97:
                cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                cout << "--------------------" << endl;
                index[cha]++;

                cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                whileFlag = 1;
                while(whileFlag)
                {
                    cout << "此選項正確還是錯誤?(Y/N) ";
                    cin >> check;
                    switch (check)
                    {
                        case 'Y':
                            cout << "繼續對話" << endl;
                            index[cha]++;
                            flag_99 = 1;
                            whileFlag = 0;
                            break;
                        case 'y':
                            cout << "繼續對話" << endl;
                            index[cha]++;
                            flag_99 = 1;
                            whileFlag = 0;
                            break;
                        case 'N':
                            cout << "請結束對話,下次對話從1開始" << endl;
                            index[cha] = 1;
                            whileFlag = 0;
                            break;
                        case 'n':
                            cout << "請結束對話,下次對話從1開始" << endl;
                            index[cha] = 1;
                            whileFlag = 0;
                            break;
                        default:
                            break;
                    }
                }
                cout << "--------------------" << endl;

                if(flag_99)
                {
                    cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                    whileFlag = 1;
                    while(whileFlag)
                    {
                        cout << "此選項正確還是錯誤?(Y/N) ";
                        cin >> check;
                        switch (check)
                        {
                            case 'Y':
                                cout << "下次對話從3開始" << endl;
                                index[cha] = 3;
                                whileFlag = 0;
                                break;
                            case 'y':
                                cout << "下次對話從3開始" << endl;
                                index[cha] = 3;
                                whileFlag = 0;
                                break;
                            case 'N':
                                cout << "下次對話從2開始" << endl;
                                index[cha] = 2;
                                whileFlag = 0;
                                break;
                            case 'n':
                                cout << "下次對話從2開始" << endl;
                                index[cha] = 2;
                                whileFlag = 0;
                                break;
                            default:
                                break;
                        }
                    }
                    cout << "--------------------" << endl;
                }
                break;
            default:
                for(int i=0; i<3; i++)
                {
                    cout << index[cha] << ": " << option_name(table_ptr[index[cha]]) << endl;
                    cout << "--------------------" << endl;
                    index[cha]++;
                    if(index[cha] == 98)
                        index[cha] = 1;
                }
                break;
        }
    }
    else
    {
        cout << "record.txt中的數字(代表目前第幾個對話)應為1~97" << endl;
    }
    cout << "--按任意鍵後將會儲存進度,若不想儲存請直接關掉程式--" << endl;
    system("pause");
    cout << "--儲存檔案--" << endl;
    writeFile();
    system("CLS");    //clear the screen
}

void readFile()
{
    fstream file;
    string buf;

    file.open("record.txt", std::fstream::in);
    file >> buf;
    file >> index[0];
    file >> buf;
    file >> index[1];
    file >> buf;
    file >> index[2];
    file >> buf;
    file >> index[3];
    file.close();
}

void writeFile()
{
    fstream file;
    file.open("record.txt", std::fstream::out | std::fstream::trunc);
    file << "艾樂莉絲 " << index[0] << endl;
    file << "艾希 " << index[1] << endl;
    file << "戴伊 " << index[2] << endl;
    file << "寇爾 " << index[3] << endl;
    file.close();
}

string option_name(int opt)
{
    switch(opt)
    {
        case 1:
            return "任務";
        case 2:
            return "修練";
        case 3:
            return "遊戲";
        case 4:
            return "食物";
        case 5:
            return "時尚";
        case 6:
            return "戀愛";
        default:
            return "0";
    }
}
