#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define BUCKET_MAX_ALLOW 1000000

void print_array(int a[], int n) {
	printf("%d",a[0]);
	for (int i=1;i<n;i++) {
		printf(",%d",a[i]);
	}
	printf("\r\n");
}

void print_array_n_check(int* a, int n) {
	printf("Checking array\r\n");
	for (int i=0;i<n-1;i++) {
		if (a[i] > a[i+1]) {
			printf("ERROR\r\n");
		}
	}

	print_array(a,n);
}

int* create_array(int n) {
	int* p_malloc = (int*)malloc(sizeof(int)*n);
	if (p_malloc) {
		for (int i=0;i<n;i++) {
			p_malloc[i] = rand() % 100; 
		}
	}
	return p_malloc;
}

int bucket_sort(int* a, int n) 
{
	int max_val = a[0];
	int min_val = a[0];
	bool b_valid = false;	// Is data valid
	int n_ret = 0;		// 0 is success; != 0 is error_code

	for (int i=1;i<n;i++) {
		if (a[i] > max_val) {
			max_val = a[i];
		}

		if (a[i] < min_val) {
			min_val = a[i];		
		}
	}

	b_valid = max_val - min_val < BUCKET_MAX_ALLOW;	// Check whether input data is valid

	if (b_valid) 
	{
		int* p_bucket = (int*) malloc(sizeof(int)*(max_val-min_val));
		int n_bucket_offset = min_val;

		if (p_bucket) 
		{
			// Now run
			memset(p_bucket, 0, sizeof(p_bucket));
			
			// Bucketing values
			for (int i=0;i<n;i++) {
				p_bucket[a[i] - n_bucket_offset]++;
			}

			// Print result
			printf("After sorting\r\n");

			for (int i=0;i<=max_val-min_val;i++) 
			{
				if (p_bucket[i] > 0) 
				{
					for (int j=0;j<p_bucket[i];j++) 
					{
						printf("%4d,", i+n_bucket_offset);
					}
				}
			}
			printf("\r\n");
		}
		else {
			printf("Failed in allocating\r\n");
			n_ret = -1;
		}

	}

	return n_ret;
}

int bubble_sort(int* a, int n) {
	/*
	 *	Algorithms
	 *		Comparing each item in the list with the item next to it,
	 *		and swapping them if required. (The largest elements has bubbled to the top of the array)
	 */
	printf("Before bubble_sort:\r\n");
	print_array(a,n);

	for (int i=n-1;i>=0;i--) {
		for (int j=1;j<=i;j++) {
			if (a[j-1] > a[j]) {
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}

	// Print result
	printf("After bubble_sort:\r\n");
	print_array(a,n);
}

int bubble_sort_invertion(int* a, int n) {
	for (int i=1;i<n-1;i++) {
		for (int j=1;j<=i;j++) {
			if (a[j-1] > a[j]) {
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int selection_sort(int* a, int n) {
	// selection sort 
	printf("Before selection sort\r\n");
	print_array(a,n);

	for (int i=0;i<n;i++) {
		int min_index = i;
		for (int j=i+1;j<n;j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}

		int tmp = a[i];
		a[i]  = a[min_index];
		a[min_index] = tmp;
	}

	printf("After selection sort:\r\n");
	print_array(a,n);
}

int insertion_sort(int* a, int n) {
	// insertion sort
	printf("Before insertion_sort\r\n");
	print_array(a,n);

	for (int i=0;i<n;i++) {
		int j = i;
		int base_val = a[i];

		// j is the new position of base_val after looping
		while (j>=0 && a[j-1] > base_val)  {
			a[j] = a[j-1];	
			//int tmp = a[j];
			//a[j] = a[j+1];
			//a[j+1] = tmp;
			j--;
		}

		a[j] = base_val;
	}

	printf("After insertion sort\r\n");
	print_array(a,n);

	return 0;
}

int merge(int *a1, int n1, int* a2, int n2, int* arr_swap) {
	// a1,a2 already is sorted 
	// arr_temp for swapping data 
	int i1 = 0;	// enum a1	
	int i2 = 0;	// enum a2
	int iw = 0;	// enum of new array

	// Merge into another array
	while (i1 < n1 || i2 < n2) {
		if (i1>=n1) {
			arr_swap[iw++] = a2[i2++];
		}
		else if (i2>=n2) {
			arr_swap[iw++] = a1[i1++];
		}
		else if (a1[i1] < a2[i2]) {
			arr_swap[iw++] = a1[i1++];
		} else {
			arr_swap[iw++] = a2[i2++];
		}
	}
	
	// Copy back to old array	
	for (int i=0;i<n1;i++) {
		a1[i] = arr_swap[i];
	}

	for (int i=0;i<n2;i++) {
		a2[i] = arr_swap[i+n1];
	}
}

int merge_sort(int *a, int n) {	
	// partition 
	int step_index = 1;
	int *arr_swap = (int*) malloc(sizeof(int)*n);

	printf("Before merge_sort\r\n");
	print_array(a,n);

	while (step_index < n) {
		// Partition by step_index
		
		int i = 0;
		while (i+step_index < n) {
			
			int right_size = (n-i-step_index < step_index) ? n-i-step_index : step_index; 

			merge(&a[i], step_index, &a[i+step_index], right_size, arr_swap);
			i+=step_index+right_size;
		}

		step_index *= 2;
	}

	free(arr_swap);
	
	printf("After merge_sort\r\n");
	print_array(a,n);
}

int quick_sort(int *a, int n) {
	int stack_left[20];
	int stack_right[20];
	int stack_count = 0;
	int l, r, pivot;

	stack_left[stack_count] = 0;
	stack_right[stack_count++] = n;

	printf("Before quick_sort\r\n");
	print_array(a,n);

	while (stack_count > 0) {
		// Pop from the stack 
		l = stack_left[stack_count-1];
		r = stack_right[--stack_count];	 

		printf("Partition for [%d,%d]\r\n", l,(r-1));
		// Partition for [l,r) (l<= x <r)
		int i=l;
		int j=r-2;	// dont care about pivot member
		// Executing 
		pivot = a[r];
		
		// Partition
		while (i<=j) {

			/*
			 * Literality describe the Partitioning algorithm:
			 * 	- The tagged [1][2] to all elements if array
			 * 		- if an element has value < pivot => tag = [1]
			 * 		- if an element has value >= pivot => tag = [2]
			 * 	- The algorithm is for sorting tag asc
			 * 		- tag[1] < tag[2]
			 * 	- How algorithms works:
			 * 		- Find the 1st element which has [2] tag from left to right.
			 * 		- Find the 1st element which has [1] tag from right to left 
			 * 		=> switch these above items if ([2] valued tag).index < ([1] valued tag).index;
			 * 		=> Algorithms ends when cant not find for switching.
			 */

			// Find 1st tag[2] from left-> right
			while (i<r && a[i]<pivot) i++; // After while: a[i] >= pivot or i==r
	
			// Find 1st tag[1] from right->left
			while (j>=l && a[j]>=pivot) j--; // After while: a[j] < pivot or j==l-1
			// Can i > j here ? <=> 
			// 	Yes i=j+1
			// 	i the 1st elemnt that a[i]>=pivot or i==end   => (a[i-1] < pivot or i-1=begin)
			// 	j the 1st element that a[j]<pivot or j==begin => (a[j+1] >= pivot or j+1=end)
			// 		j >= i-1 <=> i<=j+1
			// 		i <= j+1
			// 	i==j: Can not
			//

			// Switch for right order (tag[1]<tag[2])
			if (i<j) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}			
		}

		// If i > j => i=j+1

		// Partition ok
		// a[i] > pivot or i==r
		// a[j] < pivot <=> j the last element that > pivot
		// Partition next
		if (l<j) {
			// Push [l,j] into stack
			stack_left[stack_count] = l;
			stack_right[stack_count++] = j+1;
		}

		if (i<r-1) {
			// Push [i,r) to stack
			stack_left[stack_count] = i;
			stack_right[stack_count++] = r;
		}
	}

	printf("After quick_sort\r\n");
	print_array_n_check(a,n);

	return 0;
}

#define MAX_VALUE_LEN 100 

vector < string > braces(vector < string > values) {
    vector<string> vector_result;
    
    const char* str_braces = "{[(}])";  // Open braces & respective close braces have 3 gap character
    int BALANCED_GAP = 3;
    int stack_braces[MAX_VALUE_LEN+1];
    int stack_count = 0;
    bool b_balanced = true;
    
    // Check each string
    for (int i=0;i<values.size();i++) {

        b_balanced = true;
        stack_count = 0;    // Clean stack
        
        // Is this string balanced?
        for (int j=0;j<values[i].length();j++) {

            char ch = values[i][j];
            int n_brace_index = -1;

            cout << ch << endl;
                        
            for (int enum_brace=0;enum_brace<strlen(str_braces);enum_brace++) {
                if (ch == str_braces[enum_brace]) {
                    n_brace_index = enum_brace;
                    break;
                }
            }
            
            //Check open brace
            if (n_brace_index >=0 && n_brace_index <=2) {
                stack_braces[stack_count++] = n_brace_index;


                cout << stack_count << endl;
                print_array(&stack_braces[0], stack_count);
                cout << ch << "is open" << b_balanced << n_brace_index << endl;
            }
            
            // Check close brace
            else if (n_brace_index >= 0 && n_brace_index <=5) {
                // Pop from stack/check open 
                print_array(&stack_braces[0], stack_count);
                int current_brace = (stack_count > 0) ? stack_braces[--stack_count] : -10;
                b_balanced &= (abs(n_brace_index - current_brace) == BALANCED_GAP);


                cout << ch << "is close" << b_balanced << current_brace << n_brace_index <<endl;
            }              
        }
        
        // Must 
        b_balanced &= (stack_count == 0);
        
        vector_result.push_back(b_balanced ? "YES" : "NO");
    }

    return vector_result;
}

int inplace_reverse(char* str) {
	int n = strlen(str);

	// Mirror the string 1st
	for (int i =0;i<n/2;i++) {
		char ch = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = ch;
	}

	int type = -1;	// 0 is blank; 1 is character
	int start_pos = -1;
	int end_pos = -1;

	for (int i=0;i<n;i++) {
		int new_type = str[i] == ' ' ? 0 : 1;

		if (type != new_type) {
			// Finish a sentence
			if (type >=0) {
				end_pos = i;

				if (type == 1) {
					// Un-mirror sentence					
					for (int j=0;j<(end_pos-start_pos)/2;j++) {
						char ch = str[j+start_pos];
						str[j+start_pos] = str[end_pos-1-j];
						str[end_pos-start_pos-1-j+start_pos] = ch;
					}
				}
			}


			// Open new stack
			start_pos = i;
			type = new_type;
		} 
	}

	if (type == 1) {
		end_pos = n;	
		for (int j=0;j<(end_pos-start_pos)/2;j++) {
			char ch = str[j+start_pos];
			str[j+start_pos] = str[end_pos-1-j];
			str[end_pos-1-j] = ch;
		}
	}

	return 1;
}

int inplace_reverse_v2(char* str) {
	int n = strlen(str);

	int type = -1;	// 0 is blank; 1 is character
	int start_pos = -1;
	int end_pos = -1;

	int stack_left[500];
	int stack_right[500];
	int n_stack = 0;
	int* arr_newpos = (int*) malloc(sizeof(int)*n);
	char* str1 = (char*) malloc(sizeof(char)*n);
	int flag = 0;

	for (int i=0;i<n;i++) {
		int new_type = str[i] == ' ' ? 0 : 1;

		if (type != new_type) {
			// Finish a sentence
			// Add right_edge to stack
			if (type >=0) {
				// end of stack
				stack_right[n_stack++] = i;				
				flag = 1; // Close

				stack_left[n_stack] = i;
				flag = 0; // Open
			} else {


				// Pust left_edge to stack
				stack_left[n_stack] = i;
				flag = 0;
			}
			type = new_type;
		} 
	}

	if (flag == 0) {
		stack_right[n_stack++] = n;
	}

	//for (int i=n_stack-1;i>=0;i--) {
	//	printf("%d,%d\r\n", stack_left[i], stack_right[i]);
	//}

	// Find new position for each char
	int enum_idx = 0;
	while (n_stack > 0) {
		// Pop from stack
		int l = stack_left[n_stack-1];
		int r = stack_right[--n_stack];

		for (int i=l;i<r;i++) {
			arr_newpos[i] = enum_idx++;
		}
	}

	// printf("\r\n");
	// Switch position
	for (int i=0;i<n;i++) {
		str1[arr_newpos[i]] = str[i];
	}	
	str1[n] = 0;

	strcpy(str,str1);

	free(arr_newpos);
	free(str1);
	return 1;
}


int main(int argc, char** argv) {

	/*	
	srand(time(NULL));
	printf("Sorttype=\r\n\t1. Internal sorting\r\n\t2. External sorting");

	int a[3] { 2, 3, 2};
	bucket_sort(a,3);

	int n = 10;
	int* p_arr = NULL;

	p_arr = create_array(n);

	if (p_arr) {
		// bucket_sort(p_arr, n);
		free(p_arr);
	}

	p_arr = create_array(n);
	if (p_arr) {
		selection_sort(p_arr, n);
		free(p_arr);
	}

	p_arr = create_array(n);
	int a1[10] {10,9,8,7,6,5,4,3,2,1};
	if (p_arr) {
		insertion_sort(a1, n);
		free(p_arr);
	}

	p_arr = create_array(n);
	if (p_arr) {
		merge_sort(p_arr,n);
		free(p_arr);
	}
	p_arr = create_array(n);
	if (p_arr) {
		quick_sort(p_arr,n);
		free(p_arr);
	}

	*/


	std::string s1("1");

	char str1[] = "1";
	inplace_reverse_v2(str1);

	printf("After reverse %s\r\n",str1);

	char str2[] = "11 22 33j";
	inplace_reverse_v2(str2);

	printf("After reverse %s\r\n",str2);
	
	char str3[] = "here am i";	// "i ma ereh"
	inplace_reverse_v2(str3);

	printf("After reverse %s\r\n",str3);

	return 0;
}
