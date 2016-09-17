#include "pgmio.h"
#include <iostream>
#include <ctime>

void shuffle_image_3(PGM src, PGM & target);

int main(int argc, char ** argv) {
	srand(time(NULL));

	// both src and target contain a 2D array 
	// of the same size
	PGM src, target;
	readPGM("test.pgm", src);
	readPGM("test.pgm", target);

	shuffle_image_3(src, target);
	writePGM("test_shuffled.pgm", target);
	system("test_shuffled.pgm");
	return 0;
}

void shuffle_image_3(PGM src, PGM & target) {

	if (src.row != target.row || src.col != target.col) {
		return;
	}

	// Length and width of each individual tile in the image
	int rowLength = src.row / 3;
	int colLength = src.col / 3;

	// "used[i][j]==true" means the tile in source
	// at row i and column j has been copied to target
	// initially, they are all false, meaning none of the 
	// tiles in the source have been copied
	bool used[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			used[i][j] = false;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// randomly select a tile in the source,
			// copy the pixel values from that tile to target
			int r, c;
			do {
				// randomly select a tile in the source
				r = rand() % 3;
				c = rand() % 3;
			} while (used[r][c] == true);
			// we must have used[r][c] == false
			used[r][c] = true;

			// Nested for loop to go through all the values in a tile of the image
			for (int row = 0; row < rowLength; row++) {
				for (int col = 0; col < colLength; col++) {
					// Destination of each value is determined by calculating the offset with the starting position of each tile
					// Source of each value is determined the same way, only with the random starting values calculated earlier
					target.data[row + ((rowLength) * i)][col + ((colLength) * j)] = src.data[row + ((rowLength) * r)][col + ((colLength) * c)];
				}
			}
		}
	}
}
