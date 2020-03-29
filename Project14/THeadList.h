#pragma once
using namespace std;
#include <iostream>
template <class T>
struct TNode
{
	T val;
	TNode *pNext;
};
template <class T>
class TList
{
protected:
	TNode<T> *pFirst;
	TNode<T> *pPrev;
	TNode<T> *pCurr;
	TNode<T> *pLast;
	TNode<T> *pStop;
	int pos, len;
public:
	TList();
	~TList();

	int GetSize() { return size; }
	int GetPos() { return pos; }
	int CountSize();
	T GetCurrentEl();
	void DelFirst();
	void DelCurr();
	void DelLast();

	virtual void InsFirst(const T& elem);
	virtual void InsLast(const T& elem);
	virtual void InsCurrent(const T& elem);
	void Reset()
	{
		pCurr = pFirst;
		pos = 0;
		pPrev = pStop;
	}
	void GoNext()
	{
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}
	bool IsEnd()
	{
		return pCurr == pStop;
	}
};
template <class T>
TList<T>::TList()
	{
		pFirst = pLast = pPrev = pCurr = pStop = NULL;
		len = 0;
		pos = -1;
	}
template <class T>
TList<T>::~TList()
	{
		TNode<T> *tmp = pFirst;
		while (pFirst != pLast)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	
template <class T>
int TList<T>::CountSize()
	{
		pCurr = pFirst; int i = 0;
		while (pCurr != pStop)
		{
			i++;
			pCurr = pCurr->pNext;
		}
		return i;
	}

template <class T>
void TList<T>::InsFirst(const T &a)
	{
		TNode<T> *tmp = new TNode <T>;
		tmp->val = a;
		if (pFirst == NULL) {
			pFirst = pLast = pCurr = tmp;
			pFirst->pNext = pStop;
			pos = 0;
		}
		else {
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		len++;
		pos++;
	}
template <class T>
void TList<T>::InsLast(const T& a)
	{
		if (pFirst == NULL)
			InsFirst(a);
		else if (pLast != pStop)
		{
			TNode<T> *tmp = new TNode<T>;
			tmp->val = a;
			pLast->pNext = tmp;
			tmp->pNext = pStop;
			pLast = tmp;
			len++;
		}
	}
template <class T>
void TList<T>::DelCurr() {
		if (pCurr == pFirst) DelFirst();
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp = pCurr;
			delete pCurr;
			pCurr = tmp->pNext;
		}
	}
	
	
	template <class T>
	void TList<T>::InsCurrent(const T& a)
	{
		if (pCurr == pFirst)
			InsFirst(a);
		//if (pCurr == pStop)
			//throw 0;
		else
		{
			TNode<T> *tmp = new TNode<T>;
			tmp->val = a;
			pPrev->pNext = tmp;
			tmp->pNext = pCurr;
			pCurr = tmp;
			len++;
		}
	} 
	template <class T>
	void TList<T>::DelFirst()
	{
		if (pFirst == pLast)
			throw 1;
		TNode<T>* tmp = new TNode<T>;
		tmp = pFirst->pNext;
		delete pFirst;
		pFirst = tmp;
		len--;
		pos--;
	}
	template <class T>
	void TList<T>::DelLast() {
		if (pLast == pFirst)
			DelFirst();
		else {
			for (Reset(); !(pCurr->pNext == pStop); GoNext()) {}
			delete pLast;
			pLast = pCurr = pPrev;
			Reset();
			len--;
			pos--;
		}
	}
	template <class T>
	T TList<T>::GetCurrentEl()
	{
		return pCurr->val;
	}
	
	template <class T>
	class THeadList : public TList<T> {
	protected:
		TNode<T> *pHead;
	public:
		THeadList();
		~THeadList();

		void insFirst(const T& elem);
		void DelFirst();
	};

	template <class T>
	THeadList<T>::THeadList() : TList() {
		pHead = new TNode<T>;
		pStop = pHead;
		pHead->pNext = pHead;
	}

	template <class T>
	THeadList<T>::~THeadList() {
		TList<T>::~TList();
		delete[] pHead;
	}

	template <class T>
	void THeadList<T>::insFirst(const T& elem) {
		TList::insFirst(elem);
		pHead->pNext = pFirst;
	}

	template <class T>
	void THeadList<T>::DelFirst() {
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
	


	struct TMonom
	{
		double coeff;
		int px, py, pz;
		bool operator== (TMonom a) {
			return ((px == a.px) && (py == a.py) && (pz == a.pz));
		}
		bool operator> (TMonom a) {
			return ((px > a.px) || (px == a.px) && (py > a.py) || (px == a.px) && (py == a.py) && (pz > a.pz));
		}
		bool operator< (TMonom a) {
			return ((px < a.px) || (px == a.px) && (py < a.py) || (px == a.px) && (py == a.py) && (pz < a.pz));
		}
		bool operator>= (TMonom a) {
			return *this > a || *this == a;
		}
		bool operator<= (TMonom a) {
			return *this < a || *this == a;
		}
		TMonom operator- () {
			coeff = -coeff;
			return *this;
		}
	};

	TMonom operator+ (const TMonom & n1, const TMonom & n2) {
		if ((n1.px != n2.px) || (n1.py != n2.py) || (n1.pz != n2.pz)) {
			
			throw -4;
		} 

		TMonom res;

		res.px = n1.px;
		res.py = n2.py;
		res.pz = n2.pz;
		res.coeff = n1.coeff + n2.coeff;

		return res;
	}



	TMonom operator-(const TMonom & n1, const TMonom & n2) {
		if ((n1.px != n2.px) || (n1.py != n2.py) || (n1.pz != n2.pz)) {
			throw - 8;}
		
			TMonom res;

			res.px = n1.px;
			res.py = n2.py;
			res.pz = n2.pz;
			res.coeff = n1.coeff - n2.coeff;

			return res;
		}
		

	TMonom operator*(const TMonom & n1, const TMonom & n2) {
		TMonom res;

		res.px = n1.px + n2.px;
		res.py = n1.py + n2.py;
		res.pz = n1.pz + n2.pz;
		res.coeff = n1.coeff * n2.coeff;

		return res;
	}

	TMonom operator/(const TMonom & n1, const TMonom & n2) {
		TMonom res;

		res.px = n1.px - n2.px;
		res.py = n1.py - n2.py;
		res.pz = n1.pz - n2.pz;
		res.coeff = n1.coeff / n2.coeff;

		return res;
	}

	 TMonom operator*(const TMonom & n1, const double a) {
		TMonom res;
		res.coeff = n1.coeff * a;
		return res;
	} 
	
	
	bool operator != (const TMonom & n1, const TMonom & n2)
	{
		if (n1.px != n2.px)
			return true;
		else
			if (n1.py != n2.py)
				return true;
			else
				if (n1.pz != n2.pz)
					return true;
				else return false;
		

	}
	
	
ostream& operator<<(ostream &os, const TMonom &t) {
	os << t.coeff << "x^" << t.px << " y^" << t.py << " z^" << t.pz;
	return os;

}
class TPolinom :public THeadList<TMonom>
{
public:
	TPolinom() :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
		pHead->val.px = 0;
		pHead->val.py = 0;
	}

	TPolinom(int monoms[][2], int n) :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
		pHead->val.py = 0;
		pHead->val.px = 0;
		TMonom M;
		for (int i = 0; i < n; i++)
		{
			M.coeff = monoms[i][0];
			M.pz = monoms[i][1] % 10;
			M.px = monoms[i][1] / 100;
			M.py = (monoms[i][1] / 10) % 10;
			InsLast(M);
		}

	}
	TPolinom(TPolinom& P) :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
		pHead->val.px = 0;
		pHead->val.py = 0;

		for (P.Reset(); !P.IsEnd(); P.GoNext())
		{
			TMonom mon = P.pCurr->val;
			InsLast(mon);
		}
	}
	TPolinom& operator=(TPolinom& q);


	bool operator== (const TPolinom& p) const;
	
	void operator+=(TPolinom &q);
	void AddMonom(const TMonom & M);
	void operator-=(TMonom &q);
	
	void operator*=(TMonom &m);
	void operator*=(const double a);
	TPolinom operator*(TMonom &m);
	TPolinom operator*(TPolinom &q);
	TPolinom operator*(const double a);
	void InsInOrder(const TMonom &m);
	friend ostream& operator<<(ostream &os, TPolinom &p)
	{
		
		if (p.len) {
		
			for (p.Reset(); !p.IsEnd(); p.GoNext()) 
			{
				
				os << p.pCurr->val << " + ";
			}
			os << endl;
		}
		return os;
	} 
		
	
};


TPolinom& TPolinom::operator=(TPolinom& q) {
	while (len) {
		DelFirst();
	}
	for (q.Reset(); !q.IsEnd(); q.GoNext()) {
		InsLast(q.pCurr->val);
	}
	return *this;
}
inline bool TPolinom::operator==(const TPolinom &pol) const {
	TNode<TMonom> *i1, *i2;
	i1 = pFirst;
	i2 = pol.pFirst;
	while (i1->val == i2->val && i1->val.coeff == i2->val.coeff && i1 != pStop && i2 != pStop) {
		i1 = i1->pNext;
		i2 = i2->pNext;
	}
	return (i1 == pStop) && (i2 == pol.pStop);
}

void TPolinom::AddMonom(const TMonom &M)
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (pCurr->val == M)
		{
			pCurr->val.coeff += M.coeff;
			if (pCurr->val.coeff == 0)
			{
				DelCurr();
				break;
			}
		}
		else if (pCurr->val < M)
		{
			InsCurrent(M);
			break;
		}
	}
	if (IsEnd()) InsLast(M);
}
void TPolinom::operator+=(TPolinom& Q)
	{
	
		TMonom pm, qm, rm;
		Reset();
		Q.Reset();
		while (!Q.IsEnd())
		{
			pm = pCurr->val;
			qm = Q.pCurr->val;
			if (pm > qm && pm.coeff != NULL) { GoNext(); }

			else
				if (pm < qm)
				{
					InsCurrent(qm);
					Q.GoNext();
				}
				else {
					rm = pm;
					rm.coeff += qm.coeff;
					pCurr->val = rm;
					if (rm.coeff == 0)
						DelCurr();
					else
						GoNext();
					Q.GoNext();
				}
		
	}
	
	}
void TPolinom::operator*=(const double a) {
		if (len) {
			for (Reset(); !IsEnd(); GoNext())
				pCurr->val.coeff *= a;
		}
	}

	TPolinom TPolinom::operator*(const double a) {
		TPolinom res;
		res += *this;
		res *= a;
		return res;
	}
	void TPolinom::operator *=(TMonom& mon)
	{
		for (Reset(); !IsEnd(); GoNext())
		{
			pCurr->val.coeff *= mon.coeff;
			pCurr->val.px += mon.px;
			pCurr->val.py += mon.py;
			pCurr->val.pz += mon.pz;
		}
	}
	TPolinom TPolinom::operator*(TMonom &m) {
		TPolinom res;
		res = *this;
		res *= m;
		return res;
	}
	
	TPolinom TPolinom::operator*(TPolinom &q) {
		TPolinom res;
		for (Reset(); !IsEnd(); GoNext()) {
			for (q.Reset(); !q.IsEnd(); q.GoNext()) {
				res.InsInOrder((pCurr->val * q.pCurr->val));
			}
		}
		
		return res;
	}
	void TPolinom::operator-=(TMonom &q) {
		AddMonom(-q);
	}

	

	void TPolinom::InsInOrder(const TMonom &m) {
		if (m.coeff == 0)
			return;
		if (!len) {
			InsFirst(m);
			return;
		}
		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurr->val == m) {
				pCurr->val.coeff += m.coeff;
				if (pCurr->val.coeff == 0)
					DelCurr();
				break;
			}
			if (pCurr->val < m) {
				InsCurrent(m);
				break;
			}
			
		}
		InsLast(m);
	}
	
	
