/*
按可读格式输出 vector 和 set
类似于 PHP 的 print_r() 或 var_dump() 函数

作者：清华大学软件学院 李肇阳

创建于：
	2015-5-26
最后编辑于：
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