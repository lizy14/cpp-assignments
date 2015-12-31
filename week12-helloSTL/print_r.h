/*
���ɶ���ʽ��� vector �� set
������ PHP �� print_r() �� var_dump() ����

���ߣ��廪��ѧ���ѧԺ ������

�����ڣ�
	2015-5-26
���༭�ڣ�
	2015-5-26
*/
template<typename type>
ostream& operator << (ostream& os, const vector<type>& v){
	int i;
	int n = v.size();
	os << "Vector("<< n << ")\n(\n";
	for (i=0; i<n; i++)
		os << "    [" << i << "] => " << v[i] << "\n";
	os << ")\n";
	return os;
}

template<typename type>
ostream& operator << (ostream& os, const set<type>& s){
	os << "Set(" << s.size() << ")\n(\n";
	set<type>::iterator st;
	int i = 0;
	for (st=s.begin(); st!=s.end(); st++, i++)
		os << "    [" << i << "] => " << *st << "\n";
	os << ")\n";
	return os;
}