#include<stdio.h>
/* STUDENT NAME: BARIÞ GÝRAY AKMAN 
	STUDENT ID: 150121822
	MAIN OBJECTIVE OF THAT HOMEWORK IS PRINTING TRIANGLE/TRIANGLES DEPENDING ON 
	NUMBER OF ITERATION.  
	IMPORTANT NOTE: NUMBER OF ITERATION MUST BE LESSER THAN 5.
*/

// This function multiplies two numbers which are given as parameters.
/*This function has been created because in the PDF file, if multiplication must be used or not hasn't been declared clearly. 
It has been declared only for first question, but I have used for whole questions.*/
// There is simple condition. Both a and b mustn't be negative. Otherwise, function will not work properly.

int getMultiplication(int a, int b){
	if(b>0)
		return a+getMultiplication(a, --b);
		
	else if(b<0 && a<0){
		b=-b;
		a=-a;
		return a+getMultiplication(a, --b);
	}
	else if(b<0){
		return b+getMultiplication(b, a--);
	}
	
	else 
		return 0;
}

// This function returns the power of the number.
// Power mustn't be negative.
int getPow(int num, int pow){
	if(pow>0)
		return getMultiplication(num, getPow(num, --pow));
	else return 1;
}


// This function constructs the triangle array.
// Upper bound value stands for the upside of the inversely postured triangle.
// Depending on the upper bound value, 
void constructTriangle(int iteration, int upper_bound, char triangles[][63], int current_iteration, int i, int j){
	// If iteration is 0 or current iteration is 0, the 'if' below will be executed.
	if((iteration==0 && i!=32) || (current_iteration==0 && i!=32)){
		if(i==0){
			// Along the current column that function is working with is not equal to 31, underscore will be printed.
			 
			if(j!=31)
				triangles[i][j]='_';
			// Otherwise, 1 will be stored in the array in specified location.
			else
				triangles[i][j]='1';
			
		}
		else{
			// If one of upside blocks of triangles[i][j] are equal to 1, triangles[i][j] will be exchanged with 1.
			if(triangles[i-1][j+1]=='1' || triangles[i-1][j-1]=='1' || triangles[i-1][j]=='1' )
				triangles[i][j]='1';
			// Otherwise, triangles[i][j] will be underscore.
			else
				triangles[i][j]='_';
		}
		// If function is not at the end of the row, i will be incremented by 1 and j will be assigned to 0. 
		if(j==62)
			constructTriangle(iteration, 0, triangles, 0, ++i, 0);
		// If function is not at the end of the row, j will be incremented by 1.
		else
			constructTriangle(iteration, 0, triangles, 0, i, ++j);
		
	}
	// If creation of triangles is completed, new upper bound will be forwarded to constructTriangle recursively. 
	else if(i==32 && iteration>=current_iteration && iteration!=0)
		constructTriangle(iteration, 32/getPow(2, current_iteration), triangles, ++current_iteration, 0, 0);
	
	// If structure below will work along the time that iteration is greater than current_iteration.
	else if(iteration>=current_iteration && i!=32 && iteration !=0){
		// Same rule has been implemented.
		if(i==upper_bound && (triangles[i][j+1]=='1' && triangles[i-1][j]=='1'))
			triangles[i][j]='_';
		// If i value is between upper bound value and 2 times of upper bound, this structure will be executed.
		else if(i>upper_bound && i<upper_bound+32/getPow(2, current_iteration) && (triangles[i-1][j+1]=='_' && triangles[i-1][j-1]=='_' && triangles[i-1][j]=='_') && triangles[i][j]=='1'){
			triangles[i][j]='_';
			// If triangle is completely constructed, upper bound will be renewed up.
			if(triangles[i][j-1]=='1' && triangles[i][j+1]=='1' && triangles[i+1][j]=='_') 
				upper_bound+=2*32/getPow(2, current_iteration);
		}
		// If one of upside blocks of triangles[i][j] are equal to _, triangles[i][j] will be exchanged with _.
		if(triangles[i-1][j-1]=='_' && triangles[i-1][j]=='_' && triangles[i-1][j+1]=='_')
			triangles[i][j]='_';
		// If function is at the ending column, i will be incremented and j will be assigned to 0.
		if(j==62)
			constructTriangle(iteration, upper_bound, triangles, current_iteration, ++i, 0);
		// Otherwise, i will be same, j will be incremented by 1.
		else
			constructTriangle(iteration, upper_bound, triangles, current_iteration, i, ++j);
		
	}
}
// This function draws the triangle.
void drawTriangle(char triangles[][63], int i, int j){
	if(i!=32){
		if(j!=62){
			printf("%c", triangles[i][j]);
			drawTriangle(triangles, i, ++j);
		}
		else if(j==62){
			printf("%c\n", triangles[i][j]);
			drawTriangle(triangles, ++i, 0);
		}
	}
}
int main(void){
	char triangles[32][63]; // This array holds triangle/triangles.
	// Number of iteration mustn't be negative. Furthermore, it must be smaller than 5. Otherwise, program will not work properly.
	printf("Please enter the number of iteration: ");
	int iteration;
	scanf("%d", &iteration);
	constructTriangle(iteration, 0, triangles, 0, 0, 0); // Function is parsed in default conditions.
	printf("\n\n");
	drawTriangle(triangles, 0, 0); // Current array is displayed over the console.
	
}
