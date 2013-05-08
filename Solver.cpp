#include "Solver.h"


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

	if(nrks == 1){
		SOLVER.setZero();
		SOLVER(0,0) = 1;
		SOLVER(1,1) = 1;
		SOLVER(2,2) = 1;
	}
	else if(nrks == 2){
		SOLVER.setZero();
		for(int i=0; i<2; i++){
			SOLVER(i,i) = _t._reaksionet[0].R[i];
			SOLVER(i,i+1) = _t._reaksionet[1].R[i];
		}
		//Momentet
		SOLVER(2,2) = _t._reaksionet[0].krahu_x(_t._reaksionet[1]);
	}

	cout << SOLVER << endl;

	_t.llogarit_Momentet(_t._reaksionet[0]);

	// Krijohet vektori qe permban rezultatet nga Trari
	MatrixXd REZULTATI(3,1);
	REZULTATI << _t.Fx(), _t.Fy(), _t.M();

	// Krijojme matricen e te panjohurave
	MatrixXd PANJOHURAT(3,1);
	PANJOHURAT = SOLVER.fullPivHouseholderQr().solve(REZULTATI);

	cout << -PANJOHURAT << endl;
}