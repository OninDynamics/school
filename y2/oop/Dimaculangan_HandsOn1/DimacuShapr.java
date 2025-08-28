import java.util.Scanner;

class Rectangle {
	float width, height;

	void printAttr() {
		System.err.println("[DEBUG] Width: " + width);
		System.err.println("[DEBUG] Height: " + height);
	}

	float calculateArea() {
		return width * height;
	}

	float calculatePerimeter() {
		return 2 * (width + height);
	}

	Rectangle(float w, float h) {
		width = w;
		height = h;
	}
}

class RightTriangle {
	float width, height;

	void printAttr() {
		System.err.println("[DEBUG] Width: " + width);
		System.err.println("[DEBUG] Height: " + height);
	}

	float calculateArea() {
		return (width * height) / 2;
	}

	/* calculatePerimeter() requires sqrt(),
	 * and I don't know what package to import for that*/

	RightTriangle(float w, float h) {
		width = w;
		height = h;
	}
}

class IrregTriangle {
	float a, b, c;

	void printAttr() {
		System.err.println("[DEBUG] Sides: " + a + ", " + b + ", " + c + ", ");
	}

	float calculatePerimeter() {
		return a + b + c;
	}

	/* calculateArea() requires the trig functions,
	 * and I don't know what package to import for that*/

	IrregTriangle(float sideA, float sideB, float sideC) {
		a = sideA;
		b = sideB;
		c = sideC;
	}
}

public class DimacuShapr {
	public static void main(String[] args) {
		String userPrompt = "> ";
		Scanner in = new Scanner(System.in);

		int choice = -1;

		while (choice < 1 || choice > 3) {
			System.out.print("Choose a shape:\n" +
				"1) Rectangle\n" +
				"2) Right Triangle\n" +
				"3) Irregular Triangle\n" +
				userPrompt);
			choice = in.nextInt();

			if (choice < 1 || choice > 3) {
				System.out.println("\nThat's not in the choices!");
			}
		}

		if (choice == 1) {
			System.out.print("\nSpecify the rectangle's width: ");
			float width = in.nextFloat();

			System.out.print("\nSpecify the rectangle's height: ");
			float height = in.nextFloat();

			Rectangle shape = new Rectangle(width, height);

			System.out.println("\nYour rectangle has an area of " +
				shape.calculateArea() +
				" and a perimeter of " +
				shape.calculatePerimeter() +
				".");
		} else if (choice == 2) {
			System.out.print("\nSpecify the triangle's width: ");
			float width = in.nextFloat();

			System.out.print("\nSpecify the triangle's height: ");
			float height = in.nextFloat();

			RightTriangle shape = new RightTriangle(width, height);

			System.out.println("\nYour triangle has an area of " +
				shape.calculateArea() +
				".");
		} else if (choice == 3) {
			System.out.println("\nSpecify the triangle's side lengths...");
			float a,b,c;
			System.out.print("a" + userPrompt);
			a = in.nextFloat();
			System.out.print("b" + userPrompt);
			b = in.nextFloat();
			System.out.print("c" + userPrompt);
			c = in.nextFloat();

			IrregTriangle shape = new IrregTriangle(a, b, c);
			System.out.println("\nYour triangle has a perimeter of " +
				shape.calculatePerimeter() +
				".");
		}
	}
}
