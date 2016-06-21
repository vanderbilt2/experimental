
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int process_line(string line)
{
	int curr_max=1, max=0;

	int L=-1, R=-1, prevR=-1;
	char tmp, comma;
	int start_of_line=1;
	stringstream buffer(line);
//	cout << "process line:" << line << endl;
	while(!buffer.eof()){
		if(start_of_line==1){
			start_of_line = 0;
		}
		else{
			buffer>>comma;
//			cout << "comma:" << comma << endl;
		}
		buffer>>L;
//		cout << "L:" << L << endl;
		buffer>>tmp;
//		cout << "tmp:" << tmp << endl;
		buffer>>R;
//		cout << "R:" << R << endl;
		if(prevR==L){
			curr_max++;
			if(curr_max>max)
				max = curr_max;
		}
		else // update current max
		{
			if(curr_max>max)
				max = curr_max;
			curr_max=1;
		}
		prevR = R;
//		cout << "curr_max:" << curr_max << endl;
//		cout << "prevR:" << prevR << endl;	
//		getchar();
	}

	cout << "This line: max=" << max << endl;

	return max;
}

vector<int> domino()
{
	vector<int> results;
	ifstream fin("/home/shufei/Documents/data/t.txt");
	string line;
  if (fin.is_open())
  {
    while (getline (fin,line))
    {
      cout << line << endl;
	 int match = process_line(line);
	 results.push_back(match);
    }
    fin.close();
  }
  else cout << "Unable to open file.\n"; 

  return results;
}

int main()
{
	vector<int> ret = domino();
	cout << "process finished:" << endl;
	for(int i=0; i<ret.size(); ++i)
	{
	   cout << ret[i] << endl;
	}
	return 0;
}

