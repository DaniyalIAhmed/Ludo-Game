#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//Structure to store the positions of the token relative to the Defined PATH for Red and Yellow Tokens specifically:
struct Tokens {
	int x;
	int y;
} R1,R2,R3,R4,G1,G2,G3,G4,Y1,Y2,Y3,Y4,B1,B2,B3,B4;

// PATH: X-axis reffering to rows and Y-axis defining the columns for Red Tokens:
int arr_x_R[100] = {17,17,17,17,17,19,21,23,25,27,29,29,29,27,25,23,21,19,17,17,17,17,17,17,15,13,13,13,13,13,13,11,9,7,5,3,1,1,1,3,5,7,9,11,13,13,13,13,13,13,15,15,15,15,15,15,15};
int arr_y_R[100] = {48,44,40,36,32,29,29,29,29,29,29,27,25,25,25,25,25,25,22,18,14,10,6,2,2,2,6,10,14,18,22,25,25,25,25,25,25,27,29,29,29,29,29,29,32,36,40,44,48,52,52,48,44,40,36,32,29};

// PATH: X-axis reffering to rows and Y-axis defining the columns for Green Tokens:
int arr_y_G[100] = {25,25,25,25,25,22,18,14,10,6,2,2,2,6,10,14,18,22,25,25,25,25,25,25,27,29,29,29,29,29,29,32,36,40,44,48,52,52,52,48,44,40,36,32,29,29,29,29,29,29,27,27,27,27,27,27,27};
int arr_x_G[100] = {27,25,23,21,19,17,17,17,17,17,17,15,13,13,13,13,13,13,11,9,7,5,3,1,1,1,3,5,7,9,11,13,13,13,13,13,13,15,17,17,17,17,17,17,19,21,23,25,27,29,29,27,25,23,21,19,17};

// PATH: X-axis reffering to rows and Y-axis defining the columns for Yellow Tokens:
int arr_x_Y[100] = {13,13,13,13,13,11,9,7,5,3,1,1,1,3,5,7,9,11,13,13,13,13,13,13,15,17,17,17,17,17,17,19,21,23,25,27,29,29,29,27,25,23,21,19,17,17,17,17,17,17,15,15,15,15,15,15,15};
int arr_y_Y[100] = {6,10,14,18,22,25,25,25,25,25,25,27,29,29,29,29,29,29,32,36,40,44,48,52,52,52,48,44,40,36,32,29,29,29,29,29,29,27,25,25,25,25,25,25,22,18,14,10,6,2,2,6,10,14,18,22,25};

// PATH: X-axis reffering to rows and Y-axis defining the columns for Blue Tokens:
int arr_y_B[100] = {29,29,29,29,29,32,36,40,44,48,52,52,52,48,44,40,36,32,29,29,29,29,29,29,27,25,25,25,25,25,25,22,18,14,10,6,2,2,2,6,10,14,18,22,25,25,25,25,25,25,27,27,27,27,27,27,27};
int arr_x_B[100] = {3,5,7,9,11,13,15,17,17,17,17,17,17,19,21,23,25,27,29,29,29,27,25,23,21,19,17,17,17,17,17,17,15,13,13,13,13,13,13,11,9,7,5,3,1,3,5,7,9,11,13};

//LUDO Board:
char board[90][90] = {
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','0','0'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','1'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','2'},
	{'|','\\','\\','\\','\\','Y','2','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','Y','3','\\','\\','\\','\\','\\','|',' ','|',' ','|','x','|','\\','\\','\\','\\','\\','B','1','\\','\\','\\','\\','\\','\\','\\','\\','\\','B','2','\\','\\','\\','\\','\\','|','0','3'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','4'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','x','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','5'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','6'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','7'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','0','8'},
	{'|','\\','\\','\\','\\','Y','1','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','Y','4','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','B','4','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','B','3','\\','\\','\\','\\','\\','|','0','9'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','1','0'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','1','1'},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','1','2'},
	{'|',' ',' ',' ','|',' ','x',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ','x',' ','|',' ',' ',' ','|',' ',' ',' ','|','1','3'},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','1','4'},
	{'|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|','1','5'},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','1','6'},
	{'|',' ',' ',' ','|',' ',' ',' ','|',' ','x',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|',' ','x',' ','|',' ',' ',' ','|','1','7'},
	{'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','|','1','8'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','1','9'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','0'},
	{'|','\\','\\','\\','\\','G','3','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','G','4','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','R','4','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','R','1','\\','\\','\\','\\','\\','|','2','1'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','2'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','3'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','4'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|','x','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','5'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','6'},
	{'|','\\','\\','\\','\\','G','2','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','G','1','\\','\\','\\','\\','\\','|','x','|',' ','|',' ','|','\\','\\','\\','\\','R','3','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','R','2','\\','\\','\\','\\','\\','|','2','7'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','-','|','-','|','-','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','8'},
	{'|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|',' ','|',' ','|',' ','|','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','\\','|','2','9'},
	{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','3','0'},
	{'0','1','2','3','4','5','6','7','8','9','T','1','2','3','4','5','6','7','8','9','T','1','2','3','4','5','6','7','8','9','T','1','2','3','4','5','6','7','8','9','F','1','2','3','4','5','6','7','8','9','F','1','2','3','4'}
};


int i;
int Dice;
int TR1 = 0, TR2 = 0, TR3 = 0, TR4 = 0, TG1 = 0, TG2 = 0, TG3 = 0, TG4 = 0, TY1 = 0, TY2 = 0, TY3 = 0, TY4 = 0, TB1 = 0, TB2 = 0, TB3 = 0, TB4 = 0;
int Valid_input = 0;
char Player1_name[50] = {0};
char Player2_name[50] = {0};
char Player3_name[50] = {0};
char Player4_name[50] = {0};


//Functions:
void board_display();
int DICE();
void delay(int number_of_seconds);
void Player1();
void Player2();
void Player3();
void Player4();
void Red_token(int dice_value);
void Green_token(int dice_value);
void Yellow_token(int dice_value);
void Blue_token(int dice_value);
void board_change(int dice_value,int choice,int colour);
int six_checker(int dice_value, int choice, int colour);

int main() {
	int num;
	R1.x = -1;
	R2.x = -1;
	R3.x = -1;
	R4.x = -1;
	R1.y = -1;
	R2.y = -1;
	R3.y = -1;
	R4.y = -1;
	G1.x = -1;
	G2.x = -1;
	G3.x = -1;
	G4.x = -1;
	G1.y = -1;
	G2.y = -1;
	G3.y = -1;
	G4.y = -1;
	Y1.x = -1;
	Y2.x = -1;
	Y3.x = -1;
	Y4.x = -1;
	Y1.y = -1;
	Y2.y = -1;
	Y3.y = -1;
	Y4.y = -1;
	B1.x = -1;
	B2.x = -1;
	B3.x = -1;
	B4.x = -1;
	B1.y = -1;
	B2.y = -1;
	B3.y = -1;
	B4.y = -1;
	board_display();
	puts("Enter Name of Player 1:");
	gets(Player1_name);
	puts("Enter Name of Player 2:");
	gets(Player2_name);
	puts("Enter Name of Player 1:");
	gets(Player3_name);
	puts("Enter Name of Player 2:");
	gets(Player4_name);
	Player1();
}

void board_display() {
	printf("\t\t\tLUDO GAME\n\n");
	for(i=0; i<32; i++) {
		printf("%s\n", board[i]);
	}
}

int DICE() {
	srand(time(0));
	int num = (rand() % 6) + 1;
	return num;
}

void Red_token(int dice_value) {
	int check;
	int colour = 1;
	int choice;
	int dice = dice_value;
	if (TR1 == 0 && TR2 == 0 && TR3 == 0 && TR4 == 0 && dice_value < 6) {
		printf("No Valid moves Available!");
		Valid_input = 1;
		return 0;
	} else {
		system("cls");
		board_display();
		if(Valid_input == 1) {
			printf("No Valid Inputs available for %s\n",Player4_name);
			Valid_input = 0;
		}
		printf("Enter which token to move by DICE [%d]:\n1: R1[%d][%d]\n2: R2[%d][%d]\n3: R3[%d][%d]\n4: R4[%d][%d]\n",dice_value,arr_x_R[R1.x],arr_y_R[R1.y],arr_x_R[R2.x],arr_y_R[R2.y],arr_x_R[R3.x],arr_y_R[R3.y],arr_x_R[R4.x],arr_y_R[R4.y]);

	}
	scanf("%d",&choice);
	do {
		check = six_checker(dice, choice, colour);
		if (check == 0) {
			printf("Invalid! Try to move another token!\nEnter which token to move: ");
			scanf("%d",&choice);
		} else {
			break;
		}
	} while(1);
	board_change(dice, choice, colour);

}
void Green_token(int dice_value) {
	int check;
	int colour = 2;
	int choice;
	int dice = dice_value;
	if (TG1 == 0 && TG2 == 0 && TG3 == 0 && TG4 == 0 && dice_value < 6) {
		printf("No Valid moves Available!");
		Valid_input = 1;
		return 0;
	} else {
		system("cls");
		board_display();
		if(Valid_input == 1) {
			printf("No Valid Inputs available for %s\n",Player1_name);
			Valid_input = 0;
		}
		printf("Enter which token to move by DICE [%d]:\n1: G1[%d][%d]\n2: G2[%d][%d]\n3: G3[%d][%d]\n4: G4[%d][%d]\n",dice_value,arr_x_G[G1.x],arr_y_G[G1.y],arr_x_G[G2.x],arr_y_G[G2.y],arr_x_G[G3.x],arr_y_G[G3.y],arr_x_G[G4.x],arr_y_G[G4.y]);

	}
	scanf("%d",&choice);
	do {
		check = six_checker(dice, choice, colour);
		if (check == 0) {
			printf("Invalid! Try to move another token!\nEnter which token to move: ");
			scanf("%d",&choice);
		} else {
			break;
		}
	} while(1);
	board_change(dice, choice, colour);

}

void Yellow_token(int dice_value) {
	int check;
	int colour = 3;
	int choice;
	int dice = dice_value;
	if (TY1 == 0 && TY2 == 0 && TY3 == 0 && TY4 == 0 && dice_value < 6) {
		printf("No Valid moves Available!");
		Valid_input = 1;
		return 0;
	} else {
		system("cls");
		board_display();
		if(Valid_input == 1) {
			printf("No Valid Inputs available for %s\n",Player2_name);
			Valid_input = 0;
		}

		printf("Enter which token to move by DICE [%d]:\n1: Y1[%d][%d]\n2: Y2[%d][%d]\n3: Y3[%d][%d]\n4: Y4[%d][%d]\n",dice_value,arr_x_Y[Y1.x],arr_y_Y[Y1.y],arr_x_Y[Y2.x],arr_y_Y[Y2.y],arr_x_Y[Y3.x],arr_y_Y[Y3.y],arr_x_Y[Y4.x],arr_y_Y[Y4.y]);
	}
	scanf("%d",&choice);
	do {
		check = six_checker(dice,choice,colour);
		if (check == 0) {
			printf("Invalid! Try to move another token!\nEnter which token to move: ");
			scanf("%d",&choice);
		} else {
			break;
		}
	} while(1);
	board_change(dice, choice, colour);

}
void Blue_token(int dice_value) {
	int check;
	int colour = 4;
	int choice;
	int dice = dice_value;
	if (TB1 == 0 && TB2 == 0 && TB3 == 0 && TB4 == 0 && dice_value < 6) {
		printf("No Valid moves Available!");
		Valid_input = 1;
		return 0;
	} else {
		system("cls");
		board_display();
		if(Valid_input == 1) {
			printf("No Valid Inputs available for %s\n",Player3_name);
			Valid_input = 0;
		}

		printf("Enter which token to move by DICE [%d]:\n1: B1[%d][%d]\n2: B2[%d][%d]\n3: B3[%d][%d]\n4: B4[%d][%d]\n",dice_value,arr_x_B[B1.x],arr_y_B[B1.y],arr_x_B[B2.x],arr_y_B[B2.y],arr_x_B[B3.x],arr_y_B[B3.y],arr_x_B[B4.x],arr_y_B[B4.y]);
	}
	scanf("%d",&choice);
	do {
		check = six_checker(dice,choice,colour);
		if (check == 0) {
			printf("Invalid! Try to move another token!\nEnter which token to move: ");
			scanf("%d",&choice);
		} else {
			break;
		}
	} while(1);
	board_change(dice, choice, colour);

}

int six_checker(int dice_value, int choice, int colour) {
	if(colour == 1) {
		if (choice == 1) {
			if (TR1 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TR1 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 2) {
			if (TR2 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TR2 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 3) {
			if (TR3 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TR3 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 4) {
			if (TR4 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TR4 = 1;
				return 1;
			} else {
				return 0;
			}
		}
	}  else if (colour == 2) {
		if (choice == 1) {
			if (TG1 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TG1 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 2) {
			if (TG2 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TG2 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 3) {
			if (TG3 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TG3 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 4) {
			if (TG4 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TG4 = 1;
				return 1;
			} else {
				return 0;
			}
		}
	} else if (colour == 3) {
		if (choice == 1) {
			if (TY1 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TY1 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 2) {
			if (TY2 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TY2 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 3) {
			if (TY3 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TY3 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 4) {
			if (TY4 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TY4 = 1;
				return 1;
			} else {
				return 0;
			}
		}
	} else if (colour == 4) {
		if (choice == 1) {
			if (TB1 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TB1 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 2) {
			if (TB2 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TB2 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 3) {
			if (TB3 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TB3 = 1;
				return 1;
			} else {
				return 0;
			}
		} else if (choice == 4) {
			if (TB4 == 1) {
				return 1;
			} else if(dice_value == 6) {
				TB4 = 1;
				return 1;
			} else {
				return 0;
			}
		}
	}
}

void board_change(int dice_value,int choice,int colour) {
	// For Red Token:
	if (colour == 1) {
		if (choice == 1) {
			if (R1.x != -1) {
				if ((R1.x ==  0) || (R1.x == 8 ) || (R1.x == 13 ) || (R1.x == 21 ) || (R1.x == 26) || (R1.x == 34)) {
					if(R1.x == R2.x || R1.x == R3.x || R1.x == R4.x) {
						board[arr_x_R[R1.x]][arr_y_R[R1.y]] = 'R';
					} else {
						board[arr_x_R[R1.x]][arr_y_R[R1.y]] = 'x';
					}
				} else {
					if(R1.x == R2.x || R1.x == R3.x || R1.x == R4.x) {
						board[arr_x_R[R1.x]][arr_y_R[R1.y]] = 'R';
					} else {
						board[arr_x_R[R1.x]][arr_y_R[R1.y]] = ' ';
					}
				}
				R1.x += dice_value;
				R1.y += dice_value;
				board[arr_x_R[R1.x]][arr_y_R[R1.y]] = 'R';
				system("cls");
				board_display();
			} else {
				board[21][47] = ' ';
				R1.x ++;
				R1.y ++;
				board[arr_x_R[R1.x]][arr_y_R[R1.y]] = 'R';
				system("cls");
				board_display();
			}
		}
		if (choice == 2) {
			if (R2.x != -1) {
				if ((R2.x ==  0) || (R2.x == 8 ) || (R2.x == 13 ) || (R2.x == 21 ) || (R2.x == 26) || (R2.x == 34)) {
					if(R2.x == R1.x || R2.x == R3.x || R2.x == R4.x) {
						board[arr_x_R[R2.x]][arr_y_R[R2.y]] = 'R';
					} else {
						board[arr_x_R[R2.x]][arr_y_R[R2.y]] = 'x';
					}
				} else {
					if(R2.x == R1.x || R2.x == R3.x || R2.x == R4.x) {
						board[arr_x_R[R2.x]][arr_y_R[R2.y]] = 'R';
					} else {
						board[arr_x_R[R2.x]][arr_y_R[R2.y]] = ' ';
					}
				}
				R2.x += dice_value;
				R2.y += dice_value;
				board[arr_x_R[R2.x]][arr_y_R[R2.y]] = 'R';
				system("cls");
				board_display();
			} else {
				board[27][47] = ' ';
				R2.x ++;
				R2.y ++;
				board[arr_x_R[R2.x]][arr_y_R[R2.y]] = 'R';
				system("cls");
				board_display();
			}
		}
		if (choice == 3) {
			if (R3.x != -1) {
				if ((R3.x ==  0) || (R3.x == 8 ) || (R3.x == 13 ) || (R3.x == 21 ) || (R3.x == 26) || (R3.x == 34)) {
					if(R3.x == R1.x || R3.x == R2.x || R3.x == R4.x) {
						board[arr_x_R[R3.x]][arr_y_R[R3.y]] = 'R';
					} else {
						board[arr_x_R[R3.x]][arr_y_R[R3.y]] = 'x';
					}
				} else {
					if(R3.x == R1.x || R3.x == R2.x || R3.x == R4.x) {
						board[arr_x_R[R3.x]][arr_y_R[R3.y]] = 'R';
					} else {
						board[arr_x_R[R3.x]][arr_y_R[R3.y]] = ' ';
					}
				}
				R3.x += dice_value;
				R3.y += dice_value;
				board[arr_x_R[R3.x]][arr_y_R[R3.y]] = 'R';
				system("cls");
				board_display();
			} else {
				board[27][35] = ' ';
				R3.x ++;
				R3.y ++;
				board[arr_x_R[R3.x]][arr_y_R[R3.y]] = 'R';
				system("cls");
				board_display();
			}
		}
		if (choice == 4) {
			if (R4.x != -1) {
				if ((R4.x ==  0) || (R4.x == 8 ) || (R4.x == 13 ) || (R4.x == 21 ) || (R4.x == 26) || (R4.x == 34)) {
					if(R4.x == R1.x || R4.x == R2.x || R4.x == R3.x) {
						board[arr_x_R[R4.x]][arr_y_R[R4.y]] = 'R';
					} else {
						board[arr_x_R[R4.x]][arr_y_R[R4.y]] = 'x';
					}
				} else {
					if(R4.x == R1.x || R4.x == R2.x || R4.x == R3.x) {
						board[arr_x_R[R4.x]][arr_y_R[R4.y]] = 'R';
					} else {
						board[arr_x_R[R4.x]][arr_y_R[R4.y]] = ' ';
					}

				}
				R4.x += dice_value;
				R4.y += dice_value;
				board[arr_x_R[R4.x]][arr_y_R[R4.y]] = 'R';
				system("cls");
				board_display();
			} else {
				board[21][35] = ' ';
				R4.x ++;
				R4.y ++;
				board[arr_x_R[R4.x]][arr_y_R[R4.y]] = 'R';
				system("cls");
				board_display();
			}
		}
	}
	// For Green Token:
	if (colour == 2) {
		if (choice == 1) {
			if (G1.x != -1) {
				if ((G1.x ==  0) || (G1.x == 8 ) || (G1.x == 13 ) || (G1.x == 21 ) || (G1.x == 26) || (G1.x == 34)) {
					if(G1.x == G2.x || G1.x == G3.x || G1.x == G4.x) {
						board[arr_x_G[G1.x]][arr_y_G[G1.y]] = 'G';
					} else {
						board[arr_x_G[G1.x]][arr_y_G[G1.y]] = 'x';
					}
				} else {
					if(R1.x == G2.x || G1.x == G3.x || G1.x == G4.x) {
						board[arr_x_G[G1.x]][arr_y_G[G1.y]] = 'G';
					} else {
						board[arr_x_G[G1.x]][arr_y_G[G1.y]] = ' ';
					}
				}
				G1.x += dice_value;
				G1.y += dice_value;
				board[arr_x_G[G1.x]][arr_y_G[G1.y]] = 'G';
				system("cls");
				board_display();
			} else {
				board[27][17] = ' ';
				G1.x ++;
				G1.y ++;
				board[arr_x_G[G1.x]][arr_y_G[G1.y]] = 'G';
				system("cls");
				board_display();
			}
		}
		if (choice == 2) {
			if (G2.x != -1) {
				if ((G2.x ==  0) || (G2.x == 8 ) || (G2.x == 13 ) || (G2.x == 21 ) || (G2.x == 26) || (G2.x == 34)) {
					if(R2.x == G1.x || R2.x == G3.x || G2.x == G4.x) {
						board[arr_x_G[G2.x]][arr_y_G[G2.y]] = 'G';
					} else {
						board[arr_x_G[G2.x]][arr_y_G[G2.y]] = 'x';
					}
				} else {
					if(G2.x == G1.x || G2.x == G3.x || G2.x == G4.x) {
						board[arr_x_G[G2.x]][arr_y_G[G2.y]] = 'G';
					} else {
						board[arr_x_G[G2.x]][arr_y_G[G2.y]] = ' ';
					}
				}
				G2.x += dice_value;
				G2.y += dice_value;
				board[arr_x_G[G2.x]][arr_y_G[G2.y]] = 'G';
				system("cls");
				board_display();
			} else {
				board[27][5] = ' ';
				G2.x ++;
				G2.y ++;
				board[arr_x_G[G2.x]][arr_y_G[G2.y]] = 'G';
				system("cls");
				board_display();
			}
		}
		if (choice == 3) {
			if (G3.x != -1) {
				if ((G3.x ==  0) || (G3.x == 8 ) || (G3.x == 13 ) || (G3.x == 21 ) || (G3.x == 26) || (G3.x == 34)) {
					if(G3.x == G1.x || G3.x == G2.x || G3.x == G4.x) {
						board[arr_x_G[G3.x]][arr_y_G[G3.y]] = 'G';
					} else {
						board[arr_x_G[G3.x]][arr_y_G[G3.y]] = 'x';
					}
				} else {
					if(G3.x == G1.x || G3.x == G2.x || G3.x == G4.x) {
						board[arr_x_G[G3.x]][arr_y_G[G3.y]] = 'G';
					} else {
						board[arr_x_G[G3.x]][arr_y_G[G3.y]] = ' ';
					}
				}
				G3.x += dice_value;
				G3.y += dice_value;
				board[arr_x_G[G3.x]][arr_y_G[G3.y]] = 'G';
				system("cls");
				board_display();
			} else {
				board[21][5] = ' ';
				G3.x ++;
				G3.y ++;
				board[arr_x_G[G3.x]][arr_y_G[G3.y]] = 'G';
				system("cls");
				board_display();
			}
		}
		if (choice == 4) {
			if (G4.x != -1) {
				if ((G4.x ==  0) || (G4.x == 8 ) || (G4.x == 13 ) || (G4.x == 21 ) || (G4.x == 26) || (G4.x == 34)) {
					if(G4.x == G1.x || G4.x == G2.x || G4.x == G3.x) {
						board[arr_x_G[G4.x]][arr_y_G[G4.y]] = 'G';
					} else {
						board[arr_x_G[G4.x]][arr_y_G[G4.y]] = 'x';
					}
				} else {
					if(G4.x == G1.x || G4.x == G2.x || G4.x == G3.x) {
						board[arr_x_G[G4.x]][arr_y_G[G4.y]] = 'G';
					} else {
						board[arr_x_G[G4.x]][arr_y_G[G4.y]] = ' ';
					}

				}
				G4.x += dice_value;
				G4.y += dice_value;
				board[arr_x_G[G4.x]][arr_y_G[G4.y]] = 'G';
				system("cls");
				board_display();
			} else {
				board[21][17] = ' ';
				G4.x ++;
				G4.y ++;
				board[arr_x_G[G4.x]][arr_y_G[G4.y]] = 'G';
				system("cls");
				board_display();
			}
		}
	}

	//For Yellow Token:
	if (colour == 3) {
		if (choice == 1) {
			if (Y1.x != -1) {
				if ((Y1.x ==  0) || (Y1.x == 8 ) || (Y1.x == 13 ) || (Y1.x == 21 ) || (Y1.x == 26) || (Y1.x == 34)) {
					if(Y1.x == Y2.x || Y1.x == Y3.x || Y1.x == Y4.x) {
						board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = 'Y';
					} else {
						board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = 'x';
					}
				} else {
					if(Y1.x == Y2.x || Y1.x == Y3.x || Y1.x == Y4.x) {
						board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = 'Y';
					} else {
						board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = ' ';
					}
				}
				Y1.x += dice_value;
				Y1.y += dice_value;
				board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = 'Y';
				system("cls");
				board_display();
			} else {
				board[9][5] = ' ';
				Y1.x ++;
				Y1.y ++;
				board[arr_x_Y[Y1.x]][arr_y_Y[Y1.y]] = 'Y';
				system("cls");
				board_display();
			}
		}
		if (choice == 2) {
			if (Y2.x != -1) {
				if ((Y2.x ==  0) || (Y2.x == 8 ) || (Y2.x == 13 ) || (Y2.x == 21 ) || (Y2.x == 26) || (Y2.x == 34)) {
					if(Y2.x == Y1.x || Y2.x == Y3.x || Y2.x == Y4.x) {
						board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = 'Y';
					} else {
						board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = 'x';
					}
				} else {
					if(Y2.x == Y1.x || Y2.x == Y3.x || Y2.x == Y4.x) {
						board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = 'Y';
					} else {
						board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = ' ';
					}
				}
				Y2.x += dice_value;
				Y2.y += dice_value;
				board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = 'Y';
				system("cls");
				board_display();
			} else {
				board[3][5] = ' ';
				Y2.x ++;
				Y2.y ++;
				board[arr_x_Y[Y2.x]][arr_y_Y[Y2.y]] = 'Y';
				system("cls");
				board_display();
			}
		}
		if (choice == 3) {
			if (Y3.x != -1) {
				if ((Y3.x ==  0) || (Y3.x == 8 ) || (Y3.x == 13 ) || (Y3.x == 21) || (Y3.x == 26) || (Y3.x == 34)) {
					if(Y3.x == Y1.x || Y3.x == Y2.x || Y3.x == Y4.x) {
						board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = 'Y';
					} else {
						board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = 'x';
					}
				} else {
					if(Y3.x == Y1.x || Y3.x == Y2.x || Y3.x == Y4.x) {
						board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = 'Y';
					} else {
						board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = ' ';
					}
				}
				Y3.x += dice_value;
				Y3.y += dice_value;
				board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = 'Y';
				system("cls");
				board_display();
			} else {
				board[3][17] = ' ';
				Y3.x ++;
				Y3.y ++;
				board[arr_x_Y[Y3.x]][arr_y_Y[Y3.y]] = 'Y';
				system("cls");
				board_display();
			}
		}
		if (choice == 4) {
			if (Y4.x != -1) {
				if ((Y4.x ==  0) || (Y4.x == 8 ) || (Y4.x == 13 ) || (Y4.x == 21 ) || (Y4.x == 26) || (Y4.x == 34)) {
					if(Y4.x == Y1.x || Y4.x == Y2.x || Y4.x == Y3.x) {
						board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = 'Y';
					} else {
						board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = 'x';
					}
				} else {
					if(Y4.x == Y1.x || Y4.x == Y2.x || Y4.x == Y3.x) {
						board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = 'Y';
					} else {
						board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = ' ';
					}
				}
				Y4.x += dice_value;
				Y4.y += dice_value;
				board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = 'Y';
				system("cls");
				board_display();
			} else {
				board[9][17] = ' ';
				Y4.x ++;
				Y4.y ++;
				board[arr_x_Y[Y4.x]][arr_y_Y[Y4.y]] = 'Y';
				system("cls");
				board_display();
			}
		}
	}
	//For Blue Token:
	if (colour == 4) {
		if (choice == 1) {
			if (B1.x != -1) {
				if ((B1.x ==  0) || (B1.x == 8 ) || (B1.x == 13 ) || (B1.x == 21 ) || (B1.x == 26) || (B1.x == 34)) {
					if(B1.x == B2.x || B1.x == B3.x || B1.x == B4.x) {
						board[arr_x_B[B1.x]][arr_y_B[B1.y]] = 'B';
					} else {
						board[arr_x_B[B1.x]][arr_y_B[B1.y]] = 'x';
					}
				} else {
					if(B1.x == B2.x || B1.x == B3.x || B1.x == B4.x) {
						board[arr_x_B[B1.x]][arr_y_B[B1.y]] = 'B';
					} else {
						board[arr_x_B[B1.x]][arr_y_B[B1.y]] = ' ';
					}
				}
				B1.x += dice_value;
				B1.y += dice_value;
				board[arr_x_B[B1.x]][arr_y_B[B1.y]] = 'B';
				system("cls");
				board_display();
			} else {
				board[3][36] = ' ';
				B1.x ++;
				B1.y ++;
				board[arr_x_B[B1.x]][arr_y_B[B1.y]] = 'B';
				system("cls");
				board_display();
			}
		}
		if (choice == 2) {
			if (B2.x != -1) {
				if ((B2.x ==  0) || (B2.x == 8 ) || (B2.x == 13 ) || (B2.x == 21 ) || (B2.x == 26) || (B2.x == 34)) {
					if(B2.x == B1.x || B2.x == B3.x || B2.x == B4.x) {
						board[arr_x_B[B2.x]][arr_y_R[R2.y]] = 'B';
					} else {
						board[arr_x_B[B2.x]][arr_y_B[B2.y]] = 'x';
					}
				} else {
					if(B2.x == B1.x || B2.x == B3.x || B2.x == B4.x) {
						board[arr_x_B[B2.x]][arr_y_B[B2.y]] = 'B';
					} else {
						board[arr_x_B[B2.x]][arr_y_B[B2.y]] = ' ';
					}
				}
				B2.x += dice_value;
				B2.y += dice_value;
				board[arr_x_B[B2.x]][arr_y_B[B2.y]] = 'B';
				system("cls");
				board_display();
			} else {
				board[3][47] = ' ';
				B2.x ++;
				B2.y ++;
				board[arr_x_B[B2.x]][arr_y_B[B2.y]] = 'B';
				system("cls");
				board_display();
			}
		}
		if (choice == 3) {
			if (B3.x != -1) {
				if ((B3.x ==  0) || (B3.x == 8 ) || (B3.x == 13 ) || (B3.x == 21 ) || (B3.x == 26) || (B3.x == 34)) {
					if(B3.x == B1.x || B3.x == B2.x || B3.x == B4.x) {
						board[arr_x_B[B3.x]][arr_y_B[B3.y]] = 'B';
					} else {
						board[arr_x_B[B3.x]][arr_y_B[B3.y]] = 'x';
					}
				} else {
					if(B3.x == B1.x || B3.x == B2.x || B3.x == B4.x) {
						board[arr_x_B[B3.x]][arr_y_B[B3.y]] = 'B';
					} else {
						board[arr_x_B[B3.x]][arr_y_B[B3.y]] = ' ';
					}
				}
				B3.x += dice_value;
				B3.y += dice_value;
				board[arr_x_B[B3.x]][arr_y_B[B3.y]] = 'B';
				system("cls");
				board_display();
			} else {
				board[9][47] = ' ';
				B3.x ++;
				B3.y ++;
				board[arr_x_B[B3.x]][arr_y_B[B3.y]] = 'B';
				system("cls");
				board_display();
			}
		}
		if (choice == 4) {
			if (B4.x != -1) {
				if ((B4.x ==  0) || (B4.x == 8 ) || (B4.x == 13 ) || (B4.x == 21 ) || (B4.x == 26) || (B4.x == 34)) {
					if(B4.x == B1.x || B4.x == B2.x || B4.x == B3.x) {
						board[arr_x_B[B4.x]][arr_y_B[B4.y]] = 'B';
					} else {
						board[arr_x_B[B4.x]][arr_y_B[B4.y]] = 'x';
					}
				} else {
					if(B4.x == B1.x || B4.x == B2.x || B4.x == B3.x) {
						board[arr_x_B[B4.x]][arr_y_B[B4.y]] = 'B';
					} else {
						board[arr_x_B[B4.x]][arr_y_B[B4.y]] = ' ';
					}

				}
				B4.x += dice_value;
				B4.y += dice_value;
				board[arr_x_B[B4.x]][arr_y_B[B4.y]] = 'B';
				system("cls");
				board_display();
			} else {
				board[9][35] = ' ';
				B4.x ++;
				B4.y ++;
				board[arr_x_B[B4.x]][arr_y_B[B4.y]] = 'B';
				system("cls");
				board_display();
			}
		}
	}
}

void delay(int seconds) {
	clock_t start_time = clock();
	while (clock() < start_time + (seconds * 1000));
}

void Player1() {
	int main_dice,temp_dice,temp2_dice;
	while (!((R1.x >= 56 && R2.x >= 56 && R3.x >= 56 && R4.x >= 56) && (R1.y >= 56 && R2.y >= 56 && R3.y >= 56 && R4.y >= 56))) {
		printf("Its %s's Turn:\n",Player1_name);
		printf("Dice Rolling...\n");
		main_dice = DICE();
		printf("Dice 1: %d\n",main_dice);
		if (main_dice == 6) {
			delay(2);
			temp_dice = DICE();
			printf("Dice 2: %d\n",temp_dice);
			if (temp_dice == 6) {
				delay(2);
				temp2_dice = DICE();
				printf("Dice 3: %d\n",temp2_dice);
				if (temp2_dice == 6) {
					puts("Your turn ended!");
					Player2();
				} else {
					Red_token(main_dice);
					Red_token(temp_dice);
					Red_token(temp2_dice);
					Player2();
				}
			} else {
				Red_token(main_dice);
				Red_token(temp_dice);
				Player2();
			}
		} else {
			Red_token(main_dice);
			Player2();
		}
	}
	printf("Player 1 WINS!\n!!!CONGRATULATIONS!!!");
	exit(0);

}
void Player2() {
	int main_dice,temp_dice,temp2_dice;
	while (!((G1.x >= 56 && G2.x >= 56 && G3.x >= 56 && G4.x >= 56) && (G1.y >= 56 && G2.y >= 56 && G3.y >= 56 && G4.y >= 56))) {
		printf("Its %s's Turn:\n",Player2_name);
		printf("Dice Rolling...\n");
		main_dice = DICE();
		printf("Dice 1: %d\n",main_dice);
		if (main_dice == 6) {
			delay(2);
			temp_dice = DICE();
			printf("Dice 2: %d\n",temp_dice);
			if (temp_dice == 6) {
				delay(2);
				temp2_dice = DICE();
				printf("Dice 3: %d\n",temp2_dice);
				if (temp2_dice == 6) {
					puts("Your turn ended!");
					Player3();
				} else {
					Green_token(main_dice);
					Green_token(temp_dice);
					Green_token(temp2_dice);
					Player3();
				}
			} else {
				Green_token(main_dice);
				Green_token(temp_dice);
				Player3();
			}
		} else {
			Green_token(main_dice);
			Player3();
		}
	}
	printf("Player 2 WINS!\n!!!CONGRATULATIONS!!!");
	exit(0);

}

void Player3() {
	int main_dice,temp_dice,temp2_dice;
	while (!((Y1.x >= 56 && Y2.x >= 56 && Y3.x >= 56 && Y4.x >= 56) && (Y1.y >= 56 && Y2.y >= 56 && Y3.y >= 56 && Y4.y >= 56))) {
		printf("Its %s's Turn:\n",Player3_name);
		printf("Dice Rolling...\n");
		main_dice = DICE();
		printf("Dice 1: %d\n",main_dice);
		if (main_dice == 6) {
			delay(2);
			temp_dice = DICE();
			printf("Dice 2: %d\n",temp_dice);
			if (temp_dice == 6) {
				delay(2);
				temp2_dice = DICE();
				printf("Dice 3: %d\n",temp2_dice);
				if (temp2_dice == 6) {
					puts("Your turn ended!");
					Player4();
				} else {
					Yellow_token(main_dice);
					Yellow_token(temp_dice);
					Yellow_token(temp2_dice);
					Player4();
				}
			} else {
				Yellow_token(main_dice);
				Yellow_token(temp_dice);
				Player4();
			}
		} else {
			Yellow_token(main_dice);
			Player4();
		}
	}
	printf("Player 3 WINS!\n!!!CONGRATULATIONS!!!");
	exit(0);
}

void Player4() {
	int main_dice,temp_dice,temp2_dice;
	while (!((B1.x >= 56 && B2.x >= 56 && B3.x >= 56 && B4.x >= 56) && (B1.y >= 56 && B2.y >= 56 && B3.y >= 56 && B4.y >= 56))) {
		printf("Its %s's Turn:\n",Player4_name);
		printf("Dice Rolling...\n");
		main_dice = DICE();
		printf("Dice 1: %d\n",main_dice);
		if (main_dice == 6) {
			delay(2);
			temp_dice = DICE();
			printf("Dice 2: %d\n",temp_dice);
			if (temp_dice == 6) {
				delay(2);
				temp2_dice = DICE();
				printf("Dice 3: %d\n",temp2_dice);
				if (temp2_dice == 6) {
					puts("Your turn ended!");
					Player1();
				} else {
					Blue_token(main_dice);
					Blue_token(temp_dice);
					Blue_token(temp2_dice);
					Player1();
				}
			} else {
				Blue_token(main_dice);
				Blue_token(temp_dice);
				Player1();
			}
		} else {
			Blue_token(main_dice);
			Player1();
		}
	}
	printf("Player 4 WINS!\n!!!CONGRATULATIONS!!!");
	exit(0);

}