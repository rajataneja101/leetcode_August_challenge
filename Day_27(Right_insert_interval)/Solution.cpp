class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
	multimap<int, int> starttable; 
	multimap<int, int> endtable;
	int len = intervals.size();
	for (int i = 0; i < len; ++i)
	{
		starttable.insert(pair<int,int>(intervals[i][0], i));
		endtable.insert(pair<int, int>(intervals[i][1], i));
	}
	vector<int> result(len);
	multimap<int, int>::iterator itstart = starttable.begin();
	for (multimap<int, int>::iterator it = endtable.begin(); it != endtable.end(); ++it)
	{
		int val = it->first;
		if (itstart != starttable.end())
		{
			while (itstart != starttable.end() && itstart->first < val)
				++itstart;
			if (itstart == starttable.end())
				result[it->second] = -1;
			else
				result[it->second] = itstart->second;
		}
		else {
			result[it->second] = -1;
		}
	}
	return result;
}
};