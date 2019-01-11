#include "operations.h"

operation::operation(){    
}


void operation::add_element(entry* object){
    string word = object->get_word();
    int hash1 = hash_function1(word)%size;
    int hash2 = hash_function2(word);
    int i = 0;
    int j= 0;
    if(element_number >= size){
        cout<<"MAXIMUM LIMIT REACHED"<<endl;
        return;
    }
    if(hash_table[hash1] != NULL){
        while(1){
            j++;
            int index = (hash1 + hash2*i)%size;
            if(hash_table[index] == NULL || hash_table[index] == (entry*)-1){
                hash_table[index] = object;
                element_number++;
                break;
            }
            if(( (hash_table[index]->get_word() ).compare( object->get_word() )) == 0){
                string temp = object->get_meaning();
                hash_table[index]->add_meaning( temp );
                cout<<"MEANING CHANGED OF " <<object->get_word()<<endl;
                break;
            }
            if(j>size){
                cout<<"CANNOT ADD THIS ELEMENT"<<endl;
                break;
            }
            i++;
        }
    }    
    else{
        hash_table[hash1] = object; 
        element_number++;
    }
}


void operation::set_size(int size_input = 10000){
    this->size = size_input;
    hash_table.resize(size);
    for(int i = 0 ; i < size; i++){
        hash_table[i] = NULL;
    }
}


void operation::print(){
    for(int i = 0; i < size; i++){
        if(hash_table[i] != NULL && hash_table[i] != (entry*)-1)
            cout<<hash_table[i]->get_word()<<" -> "<<hash_table[i]->get_meaning()<<endl;
        if(hash_table[i] == (entry*)-1){
            cout<<"MARKER"<<endl;
        }
    }
}


int operation::size_of_dict(){
    return element_number;
}


void operation::remove(string input){
    int hash1 = hash_function1(input)%size;
    int hash2 = hash_function2(input);
    int i = 0, flag = 0, j = 0;
    while(1){
        j++;
        int index = (hash1 + hash2*i)%size;
        if(hash_table[index]!=NULL && hash_table[index] != (entry*)-1 && hash_table[index]->get_word().compare(input) == 0 ){
            hash_table[index] = (entry*)(-1);
            flag = 1;
            element_number--;
            break;
        }
        if(j>size){
            break;
        }
        i++;
    }
    if(flag == 0)
        cout<<"CANNOT DELETE THIS ELEMENT"<<endl;

}

void operation::spellCheck(string& s){
    vector<string> v;
    int flag = 0;
    for(int i = 0 ; i < size; i++){
        if(hash_table[i] != NULL && hash_table[i] != (entry*)(-1)){
            int dis  = distance(hash_table[i]->get_word(), s);
            if(dis == 0){
                cout<<"Meaning is -> "<<hash_table[i]->get_meaning()<<endl;
                flag = 1;
                return;
            }
            else if(dis <= 2 && dis >= 1){
                cout<<"distance is "<<dis<<endl;
                v.push_back(hash_table[i]->get_word());
            }
        }
    }    

    if(flag == 0 && !v.empty()){
        cout<<"SIMILAR WORDS ARE"<<endl;
        for(int i = 0 ; i < v.size(); i++){
            cout<<v[i]<<endl;
        }
    }
    else{
        cout<<"NO SIMILAR WORDS"<<endl;
    }
}


int min(int **a,int r,int c){
    int min=1000;
    if(a[r-1][c-1]<min)
        min=a[r-1][c-1];
    if(a[r-1][c]<min)
        min=a[r-1][c];
    if(a[r][c-1]<min)
        min=a[r][c-1];
    return min;
}



// int operation::distance(string s, string t) {
//   int d[][]; // matrix
//   int n; // length of s
//   int m; // length of t
//   int i; // iterates through s
//   int j; // iterates through t
//   char s_i; // ith character of s
//   char t_j; // jth character of t
//   int cost; // cost

//     // Step 1

//     n = s.length ();
//     m = t.length ();
//     if (n == 0)
//       	return m;
//     if (m == 0) 
//       	return n;
//     d = new int[n+1][m+1];
// 	for (i = 0; i <= n; i++) {
//       		d[i][0] = i;
//     	}
//     for (j = 0; j <= m; j++) {
//       	d[0][j] = j;
//     }
//     for (i = 1; i <= n; i++) {
//       s_i = s.charAt (i - 1);

//       // Step 4

//       for (j = 1; j <= m; j++) {

//         t_j = t.charAt (j - 1);

//         // Step 5

//         if (s_i == t_j) {
//           cost = 0;
//         }
//         else {
//           cost = 1;
//         }

//         // Step 6

//         d[i][j] = Minimum (d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1] + cost);

//       }

//     }

//     // Step 7

//     return d[n][m];

//   }

// }

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

int operation::Minimum (int a, int b, int c)
{
int mi;

  mi = a;
  if (b < mi) {
    mi = b;
  }
  if (c < mi) {
    mi = c;
  }
  return mi;

}

//**************************************************
// Get a pointer to the specified cell of the matrix
//************************************************** 

int* operation::GetCellPointer (int *pOrigin, int col, int row, int nCols)
{
  return pOrigin + col + (row * (nCols + 1));
}

//*****************************************************
// Get the contents of the specified cell in the matrix 
//*****************************************************

int operation::GetAt (int *pOrigin, int col, int row, int nCols)
{
int *pCell;

  pCell = GetCellPointer (pOrigin, col, row, nCols);
  return *pCell;

}

//*******************************************************
// Fill the specified cell in the matrix with the value x
//*******************************************************

void operation::PutAt (int *pOrigin, int col, int row, int nCols, int x)
{
int *pCell;

  pCell = GetCellPointer (pOrigin, col, row, nCols);
  *pCell = x;

}

//*****************************
// Compute Levenshtein distance
//*****************************

int operation::distance(const string& s,const string& t){
    int n; // length of s
    int m; // length of t
    int i; // iterates through s
    int j; // iterates through t
    char s_i; // ith character of s
    char t_j; // jth character of t
    int cost; // cost
    int result; // result
    int cell; // contents of target cell
    int above; // contents of cell immediately above
    int left; // contents of cell immediately to left
    int diag; // contents of cell immediately above and to left
    //int sz; // number of cells in matrix


    n = s.length();
    m = t.length();
    if (n == 0) 
        return m;

    if (m == 0) {
        return n;
    }
    int sz = (n+1) * (m+1) * sizeof (int);
    int* d = (int *) malloc(sz);

    for(i = 0; i <= n; i++){
        PutAt (d, i, 0, n, i);
    }

    for (j = 0; j <= m; j++) {
        PutAt (d, 0, j, n, j);
    }

    for (i = 1; i <= n; i++) {
        s_i = s[i-1];
        for (j = 1; j <= m; j++) {
        t_j = t[j-1];
        if (s_i == t_j) {
            cost = 0;
        }
        else {
            cost = 1;
        }
        above = GetAt (d,i-1,j, n);
        left = GetAt (d,i, j-1, n);
        diag = GetAt (d, i-1,j-1, n);
        cell = Minimum (above + 1, left + 1, diag + cost);
        PutAt (d, i, j, n, cell);
        }
    }

  // Step 7

  result = GetAt (d, n, m, n);
  free (d);
  return result;
}
