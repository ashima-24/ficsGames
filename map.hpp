#include <vector>


using namespace std;

class ColumnMap

{   
     bool flag = false;

    public:
            vector<string>colHead;
           
            vector<pair<string, string>> tempColVal;

            void update(ChessGame &g);
            /*ColumnMap()
            {
                 colHead.assign(20, "null");

            }*/
            
    
};
void ColumnMap::update(ChessGame &g)
{
    //g.display(g.colVal);
   
    
  
        for (size_t i = 0; i < g.colVal.size(); ++i)
        {
        /* code */
            for(size_t j = 0; j< colHead.size(); ++j)
            {
                if (colHead[j] == g.colVal[i].second.first)
            {       flag = true;
                    break;
            }
                else
                    flag = false;

            }
            if (flag == false)
            {
                colHead.push_back(g.colVal[i].second.first);
            }
            
            
           
            
            //cout<<colHead[i]<<"\n";
         }
    

                   
            
    

 

}