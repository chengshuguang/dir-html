#include <iostream>
#include <list>
using namespace std;

void sortDiffs()
{
	list<Diff*>::iterator it;
	list<Diff*>::iterator it2;//+
	list<Diff*>::iterator it3;//-
	for(it = diffs.begin();it != diffs.end(); it++)
	{
		if((*it)->operation == INSERT)
		{
			it2 = it++;
			for(;it!=diffs.end();it++)
			{
				if((*it)->operation == EQUAL)
				{
					break;
				}
				else if((*it)->operation == INSERT)
				{
					continue;
				}
				else
				{
					it3 = it;
					diffs.splice(it2,diffs,it3);
				}
			}
		}
		if(it == diffs.end())
			break;
	}
	
}
int main()
{
	return 0;
}