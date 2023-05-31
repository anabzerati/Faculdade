import javax.swing.SwingUtilities;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.MenuBar;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JPasswordField;

public class SwingHelloWorld {

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				createAndShowText();
			}
		});
	}

	/*private static void createAndShow() {
		JFrame f = new JFrame("Swing Hello World!");
		JLabel label = new JLabel("Oi amor <3",JLabel.CENTER);
		label.setForeground(Color.pink);
		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(500,500);
		f.setVisible(true);
		f.add(label);
	}*/
	
	private static void createAndShowText() {
		JFrame f = new JFrame("Swing interativo!");
		
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		JTextField tField = new JTextField(10);
		JTextField tFieldEnter = new JTextField("Enter text here:");
		JTextField tFieldUneditable = new JTextField("Uneditable text field.", 21);
		tFieldUneditable.setEditable(false);
		
		f.add(tField);
		f.add(tFieldEnter);
		f.add(tFieldUneditable);
		
		JPasswordField passField = new JPasswordField("HiddenText");
		f.add(passField);
		
		f.setVisible(true);
	}
}
 