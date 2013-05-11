#include "Solver.h"

bool SOLVER_MATRIX_DEBUG = false;

Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

void Solver::zgjidh(Tra _t)
{
	// Llogaritet numri i reaksioneve ne Tra
	int nrks = _t._nrk;

	// Llogaritet numri i te panjohurave ne sistem
	// duke u bazuar ne numrin e reaksioneve
	int npan = 0;
	for(int i=0; i<nrks; i++){
		for(int j=0; j<3; j++){
			npan += _t._reaksionet[i].R[j];
		}
	}
		
	// Krijohet matrica katrore zgjidhese ( npan x npan )
	MatrixXd SOLVER(npan, npan);
	double *X = new double[npan];
	if(nrks == 1){
		//Inkastrim
		SOLVER.setZero();
		SOLVER(0,0) = 1;
		SOLVER(1,1) = 1;
		SOLVER(2,2) = 1;
		X[0] = _t.Fx();
		X[1] = _t.Fy();
		_t.llogarit_Momentet(_t._reaksionet[0]);
		X[2] = _t.M();
	}
	else if(nrks == 2){
		int indices[3] = {0, 0, 1};
		SOLVER.setZero();
		SOLVER(0,0) = 1;
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<3; j++)
				SOLVER(i+1,j) = _t._reaksionet[i].krahu(_t._reaksionet[indices[j]], j);
		}

		X[0] = _t.Fx();
		for(int i=1; i<npan; i++){
			_t.llogarit_Momentet(_t._reaksionet[indices[i]]);
			X[i] = _t.M();
		}
	}

	if(SOLVER_MATRIX_DEBUG)
		cout << SOLVER << endl;

	// Krijohet vektori qe permban rezultatet nga Trari
	MatrixXd REZULTATI(3,1);
	REZULTATI << X[0], X[1], X[2];

	// Krijojme matricen e te panjohurave
	MatrixXd PANJOHURAT(3,1);
	PANJOHURAT = SOLVER.fullPivHouseholderQr().solve(REZULTATI);

	// Printimi i rezultatit

	Reaksion *R = new Reaksion[nrks];

	/*for(int i=0; i<nrks; i++){
		cout << "Reaksion ";
		R[i].lloji(_t._reaksionet[i].lloji());
		R[i].emri(_t._reaksionet[i].emri());
		R[i].pozita(_t._reaksionet[i].x(), _t._reaksionet[i].y());
		if(nrks==1)
			R[i].Fx(-PANJOHURAT(0)); R[i].Fy(-PANJOHURAT(1)); R[i].moment(-PANJOHURAT(2));
		if(i>1)
			R[i-1].Fx(-PANJOHURAT(0)); R[i-1].Fy(-PANJOHURAT(1)); R[i].Fy(-PANJOHURAT(3));
		cout << R[i] << endl;
	}*/

	cout << -PANJOHURAT << endl;

}