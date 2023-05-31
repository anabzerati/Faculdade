package Botao;

import javax.swing.*;

public class Main {
	public static void main(String[] args) {
		JFrame frame = new JFrame("Botão que muda a cor");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		MyPanel panel = new MyPanel();
		frame.add(panel);
		
		frame.setSize(250,150);
		frame.setVisible(true);
	}
}
