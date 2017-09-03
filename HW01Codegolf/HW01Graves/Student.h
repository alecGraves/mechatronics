struct Student { 
	int n, c[9], g[9];
	void SetGrades(int *C, char *G, int N){
		for (int i(0); i < N; ++i){
			AddGrade(C[i], G[i]);
		}
	}
	void AddGrade(int C, char G){
		c[n] = C;
		g[n++] = G;
	}
	double GetGPA(){
		int h(0), w(0);
		for (int i(0); i < n; ++i){
			if(g[i] < 69) w += (69-g[i])*c[i];
			h += c[i];
		}
		return (float)w / h;
	}
	Student() :n(0) {}
};