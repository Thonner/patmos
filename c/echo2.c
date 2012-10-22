/*
	This program echos the characters it receives

	Author: Sahar
	Copyright: DTU, BSD License
*/

int main() {

	volatile int *uart_stat_ptr = (int *) 0xF0000000;
	volatile int *uart_val_ptr = (int *) 0xF0000004;	
	volatile int *led_ptr = (int *) 0xF0000200;
	int i, j;
	int flag = 0;
	int cmp1 = 2;
	int cmp2 = 1;
	int status;
	char  read_val;
	
	for (;;) {
		
		while (!flag )
		{
			status = *uart_stat_ptr & cmp1;
			if (status == 2)
				{flag = 1; break;}
				
		}
		read_val =  *uart_val_ptr;
		flag = 0;
		while (!flag )
		{
			status = *uart_stat_ptr & cmp2;
			if (status == 1)
				{flag = 1; break;}
				
		}
		*uart_val_ptr = read_val;
		flag = 0;
	}
}

