#include "Quiz.h"

int main()
{
    //string FilePath = "C:/Users/David/Documents/GitHub/OOP-19clc2-quiz_game/data/test.bin";
    ///*Player* plrs = new Player;
    //plrs->setUserName("name");
    //plrs->setPassword("pass");
    //savePlayerList(FilePath, plrs, 1);*/
    //login();

    Player x;
    x.setUserName("DTKN");
    x.setPassword("Chabifami");
    Player* y = &x;

    savePlayerList("User.txt", y, 1);
    /*Player* plrs = new Player;
    plrs->setUserName("name");
    plrs->setPassword("pass");
    savePlayerList(FilePath, plrs, 1);*/
    //login();
   //createTopic();
    //Question q;
    vector<Question> Q;
    loadQuestionList(QUESTION_PATH_DATA, Q);
    cout << "t " << Q.size() << endl;
    for (int i = 0; i < Q.size(); i++)
        Q[i].print();
    return 0;
}