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
	TNode<T> *pFirst, *pLast, *pCurr, *pPrev, *pStop;
	int pos, len;
public:
	TList()
	{
		pFirst = 0;
		pLast = 0;
		pCurr = 0;
		pPrev = 0; 
		pStop = 0;
		pos = 0;
		len = 0;
	}
	~TList()
	{
		TNode<T> *tmp = pFirst;
		while (pFirst != pLast)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
	}
	
	int CountSize()
	{
		pCurr = pFirst; int i = 0;
		while (pCurr != pStop)
		{
			i++;
			pCurr = pCurr->pNext;
		}
		return i;
	}

	void InsLast(T a)
	{
		TNode<T> *tmp = new TNode<T>;
		tmp->val = a;
		tmp->pNext = pStop;
		if (pLast != pStop)
		{
			pLast->pNext = tmp;
			pLast = tmp;
		}
		else 
		{
			pFirst = pLast = tmp;
		}
		len++;
	}
	void DelCurr() {
		if (pCurr == pFirst) DelFirst();
		else {
			TNode<T>* tmp = new TNode<T>;
			tmp = pCurr;
			delete pCurr;
			pCurr = tmp->pNext;
		}
	}
	void InsFirst(T a)
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
	/*void InsPos(T a, int pos)
	{
		if (pos == 0) InsFirst(a);
		else if (pos >= CountSize()) InsLast();
		else
		{
			TNode *tmp = new TNode;
			tmp->val = a;
			TNode *Curr = pFirst;
			TNode *Pred;
			for (int i = 0; i < pos; i++)
			{
				Pred = Curr;
				Curr = Curr->pNext;
			}
			Pred->pNext = tmp;
			tmp->pNext = Curr;
		}
	} */
	void InsCurrent(T a)
	{
		if (pCurr == pFirst)
			InsFirst(a);
		if (pCurr == pStop)
			throw 0;
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
	void DelFirst()
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
	T GetCurrentEl()
	{
		return pCurr->val;
	}
	void Reset()
	{
		pCurr = pFirst;
		pPrev = pStop;
		pos = 0;
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
	void InsInOrder(T el)
	{
		if (pFirst == pStop || el > pFirst->val)
			InsFirst(el);
		else if (pLast->val > el)
			InsLast(el);
		else 
		{
			for (Reset(); !IsEnd(); GoNext())
			{
				if (el > pCurr->val)
				
				{
					InsCurrent(el);
					break;
				}
		}
		}
	}
	
};
template <class T>
class THeadList: public TList<T>
{
protected:
	TNode<T> *pHead;
public:
	THeadList():TList<T>()
	{
		pHead = new TNode<T>;
		pHead->pNext = pHead;
		pStop = pHead;
	}
	
	~THeadList()
	{
		TNode<T> *tmp = pFirst;
		while (pFirst != pLast)
		{
			pFirst = pFirst->pNext;
			delete tmp;
			tmp = pFirst;
		}
		delete pHead;
	}
	void InsFirst(T a)
	{
		TList::InsFirst(a);
		pHead->pNext = pFirst;
	}
	void DelFirst()
	{
		TList::DelFirst();
		pHead->pNext = pFirst;
	}
};
struct TMonom
{
	double coeff;
	int px, py, pz;
	TMonom()
	{
		coeff = 0;
		px = 0;
		py = 0;
		pz = 0;
	}
	bool operator> ( const TMonom & n) {
	
		if (this->px > n.px) {
			return true;
			if (this->py > n.py) {
				return true;
				if (this->pz > n.pz) {
					return true;
				}
			}
		}
		else
			return false;
	}

	bool operator< (const TMonom& n) {
		if (this->px < n.px) {
			return true;
			if (this->py < n.py) {
				return true;
				if (this->pz < n.pz) {
					return true;
				}
			}
		}
		else
			return false;
	}


	TMonom operator+ (const TMonom& t) {
		if ((this->px != t.px) || (this->py != t.py) || (this->pz != t.pz)) {
			
			throw -4;
		}

		TMonom res;

		res.px = t.px;
		res.py = t.py;
		res.pz = t.pz;
		res.coeff = this->coeff + t.coeff;

		return res;
	}

	TMonom operator-(const TMonom& t) {
		if ((this->px != t.px) || (this->py != t.py) || (this->pz != t.pz)) {
			throw -8;
		}

		TMonom res;

		res.px = t.px;
		res.py = t.py;
		res.pz = t.pz;
		res.coeff = this->coeff - t.coeff;

		return res;
	}

	TMonom operator*(const TMonom& t) {
		TMonom res;

		res.px = this->px + t.px;
		res.py = this->py + t.py;
		res.pz = this->pz + t.pz;
		res.coeff = this->coeff * t.coeff;

		return res;
	}

	TMonom operator/(const TMonom& t) {
		TMonom res;

		res.px = this->px - t.px;
		res.py = this->py - t.py;
		res.pz = this->pz - t.pz;
		res.coeff = this->coeff / t.coeff;

		return res;
	}

	 TMonom operator*( const double a) {
		coeff = this->coeff * a;
		return *this;
	}

	
	bool operator== (TMonom a)
	{
		if (a.px == this->px)
		{
			if (a.py == this->py)
				if (a.pz == this->pz)
					return true;
		}

	}
	bool operator != (TMonom a)
	{
		if (a.px != this->px)
			return true;
		else
			if (a.py != this->py)
				return true;
			else
				if (a.pz != this->pz)
					return true;
				else return false;
		

	}
	void operator = (TMonom a)
	{
		this->coeff = a.coeff;
		this->pz = a.pz;
		this->py = a.py;
		this->px = a.px;

	}
	friend ostream& operator<<(ostream &os, const TMonom &t);
};
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
		pHead-> val.coeff = 0;
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
	TPolinom( TPolinom &P) :THeadList<TMonom>()
	{
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
		pHead->val.px = 0;
		pHead->val.py = 0;
		TMonom M;
		for (P.Reset(); !P.IsEnd(); P.GoNext())
		{
			M = P.pCurr->val;
			InsLast(M);
		}
	}
	TPolinom& operator=(TPolinom &p) 
	{
		int l = len;
		for (int i = 0; i < l; i++)
			DelFirst();
		for (p.Reset(); !p.IsEnd(); p.GoNext()) {
			InsLast(p.pCurr->val);
		}
		return *this;
	}

	
	void operator+=(TMonom& mon) {
		for (Reset(); !IsEnd(); GoNext()) {
			if (pCurr->val == mon) 
			{
				pCurr->val = pCurr->val + mon;
				if (!pCurr->val.coeff)
					DelCurr();
				else
					return;
			}
			if (mon > pCurr->val) {
				InsCurrent(mon);
				return;
			}
		}
		InsLast(mon);
	}

	TPolinom operator+(TMonom& mon) {
		TPolinom res = *this;
		res += mon;
		return res;
	}
	
	friend ostream& operator<<(ostream &os, TPolinom &p) {
		if (p.len) {
			for (p.Reset(); !p.IsEnd(); p.GoNext()) {
				os << p.pCurr->val << " + ";
			}
			os << ".";
		}
		else
			os << "0";
		return os;
	}
};