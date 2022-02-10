#include <iostream>
#include <ctime>
#include "myconsole.h"
#include "mygraphics.h"

using namespace std;

class linklist
{
	class node
	{
	public:
		node* next;
		int i;
		int j;
		int val;
		friend class linklist;
		node()
		{
			next = nullptr;
			i = 0;
			j = 0;
			val = 0;
		}
	};
private:
	node* head;
public:
	friend class stack;
	linklist()
	{
		head = nullptr;
	}

	void insert_at_tail(int i, int j, int val)
	{
		if (head == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;
			head = n;
		}
		else if (head->next == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;
			head->next = n;

		}
		else
		{
			node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}

			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;

			curr->next = n;

		}
	}

	void remove_From_Tail()
	{
		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				head = nullptr;
			}
			else
			{
				node* curr = head;
				node* temp = head;
				while (curr->next != nullptr)
				{
					curr = curr->next;
					if (curr->next != nullptr)
					{
						temp = temp->next;
					}
				}

				temp->next = nullptr;
				delete curr;

			}
		}
	}

	void remove_From_head()
	{
		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				head = nullptr;
			}
			else
			{
				node* curr = head;
				node* temp = head;
				curr = curr->next;
				head = curr;
				temp->next = nullptr;
			}
		}
	}

	void print()
	{

		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				cout << "i is : " << head->i << " j is : " << head->j << " val is : " << head->val << endl;
			}
			else
			{
				node* curr = head;
				while (curr != nullptr)
				{
					cout << "i is : " << curr->i << " j is : " << curr->j << " val is : " << curr->val << endl;
					curr = curr->next;
				}
			}
		}

	}

	void top(int& i, int& j, int& val)
	{
		if (head != nullptr)
		{
			node* curr = head;
			i = curr->i;
			j = curr->j;
			val = curr->val;
		}
	}

	bool is_emp()
	{
		if (head == nullptr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

};
class queue
{
private:
	linklist l;
public:
	void enqueue(int i, int j, int val)
	{
		l.insert_at_tail(i, j, val);
	}
	void dequeue()
	{
		l.remove_From_head();
	}

	void show()
	{
		l.print();
	}

	void s_data(int& i, int& j, int& val)
	{
		l.top(i, j, val);
	}

	bool is_emp()
	{
		if (l.is_emp())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

queue q;

void show(int**& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void allocate(int**& arr, int size)
{
	srand(time(0));
	arr = new int* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 2;
		}
		i++;
	}
}

void back_track(int**& arr, int x1, int x2, int rows, int cols)
{
	int count = arr[x1][x2];
	while (arr[x1][x2] > 4)
	{
		if (x1 == rows - 1)
		{
			if (arr[x1][x2 - 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2--;

				count--;
			}
			else if (arr[x1][x2 + 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2++;

				count--;
			}
			else if (arr[x1 - 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1--;

				count--;
			}

		}
		else if (x1 == 0)
		{
			if (arr[x1][x2 - 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2--;

				count--;
			}
			else if (arr[x1][x2 + 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2++;

				count--;
			}
			else if (arr[x1 + 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1++;

				count--;
			}
		}
		else if (x2 == cols - 1)
		{
			if (arr[x1][x2 - 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2--;

				count--;
			}
			else if (arr[x1 - 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1--;

				count--;
			}
			else if (arr[x1 + 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1++;

				count--;
			}
		}
		else if (x2 == 0)
		{
			if (arr[x1][x2 + 1] == count - 1)
			{
				arr[x1][x2] = 100;
				x2++;

				count--;
			}
			else if (arr[x1 - 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1--;

				count--;
			}
			else if (arr[x1 + 1][x2] == count - 1)
			{
				arr[x1][x2] = 100;
				x1++;

				count--;
			}
		}
		else if (arr[x1][x2 - 1] == count - 1)
		{
			arr[x1][x2] = 100;
			x2--;

			count--;
		}
		else if (arr[x1][x2 + 1] == count - 1)
		{
			arr[x1][x2] = 100;
			x2++;

			count--;
		}
		else if (arr[x1 - 1][x2] == count - 1)
		{
			arr[x1][x2] = 100;
			x1--;

			count--;
		}
		else if (arr[x1 + 1][x2] == count - 1)
		{
			arr[x1][x2] = 100;
			x1++;

			count--;
		}
		Sleep(300);
		drawboard(arr, rows);
	}
	arr[x1][x2] = 100;
	drawboard(arr, rows);
}

void movement(int**& arr, int size, int i, int j, int x, int y)
{

	int val = 4;
	q.enqueue(i, j, val);
	//q.s_data(i, j, val);
	while (arr[i][j] != arr[x][y] && q.is_emp() != 1)
	{
		q.dequeue();

		if (j + 1 < size && arr[i][j + 1] != 1 && arr[i][j + 1] != 2 && arr[i][j + 1] < 4)
		{
			//j++;
			q.enqueue(i, j + 1, val);
			arr[i][j + 1] = val;
		}

		if (i + 1 < size && arr[i + 1][j] != 1 && arr[i + 1][j] != 2 && arr[i + 1][j] < 4)
		{
			//i++;
			q.enqueue(i + 1, j, val);
			arr[i + 1][j] = val;
		}

		if (j - 1 >= 0 && arr[i][j - 1] != 1 && arr[i][j - 1] != 2 && arr[i][j - 1] < 4)
		{
			//j--;
			q.enqueue(i, j - 1, val);
			arr[i][j - 1] = val;
		}

		if (i - 1 >= 0 && arr[i - 1][j] != 1 && arr[i - 1][j] != 2 && arr[i - 1][j] < 4)
		{
			//i--;
			q.enqueue(i - 1, j, val);
			arr[i - 1][j] = val;
		}

		Sleep(10);
		drawboard(arr, size);
		q.s_data(i, j, val);
		val++;
		if (arr[i][j] == arr[x][y])
		{
			cout << "PATH FOUND : ";
			back_track(arr, x, y, size, size);
			break;
		}

	}
	if (q.is_emp() == 1)
	{
		cout << "\nPATH NOT FOUND/ NOT POSSIBLE\n";
	}
}

int main()
{
	maximized();

	cout << "ENTER THE SIZE OF MAZE : ";
	int size = 0;
	cin >> size;
	int** arr = nullptr;
	allocate(arr, size);
	//show(arr,size);
	drawboard(arr, size);

	int i = 0, x = 0;
	int j = 0, y = 0;
	int flag = 0, flagi = 0;
	cout << "ENTER SOURCE STARTING POINT I : ";
	cin >> i;
	cout << "ENTER SOURCE STARTING POINT J : ";
	cin >> j;
	if (arr[i][j] == 1)
	{
		cout << " \nUnsuccessfull Path Due To Source/Destination Is Hurdle \n\n ";
		flag = 0;
	}
	else
	{
		arr[i][j] = 2;
		flag = 1;
	}

	cout << "ENTER SOURCE ENDING POINT I : ";
	cin >> x;
	cout << "ENTER SOURCE ENDING POINT J : ";
	cin >> y;
	if (arr[x][y] == 1)
	{
		cout << " \nUnsuccessfull Path Due To Source/Destination Is Hurdle\n\n";
		flagi = 0;
	}
	else
	{
		arr[x][y] = -1;
		flagi = 1;
	}
	drawboard(arr, size);
	//show(arr,size);

	if(flag == 1 && flagi == 1)
		movement(arr, size, i, j, x, y);
	else
	{
		cout << " \nUnsuccessfull Path Due To Source/Destination Is Hurdle\n\n";
	}

	//q.show();


	return 0;
}