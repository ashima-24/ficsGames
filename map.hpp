#include <vector>


using namespace std;

class ColumnMap
{
    public:
            vector<string>colHead;
            //colHead.assign(20, NULL);
            vector<pair<string, string>> tempColVal;

            void update(ChessGame &g);
            
    
};
void ColumnMap::update(ChessGame &g)
{
    //cout<<"map class ";

    //g.display(g.colVal);

    //colHead.clear();

    for (size_t i = 0; i < g.colVal.size(); i++)
    {
        /* code */
        colHead.push_back(g.colVal[i].first);
        //cout<<colHead[i]<<"\n";
    }
    


    

 

}