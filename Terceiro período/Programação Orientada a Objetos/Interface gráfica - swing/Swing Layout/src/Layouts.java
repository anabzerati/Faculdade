import java.awt.*;
import javax.swing.*;
import javax.swing.UIManager.LookAndFeelInfo;

public class Layouts {
	public static void main(String[] args) {
		try {
			//UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
			//UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
			
			for(LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
				if("Nimbus".equals(info.getName())) {
					UIManager.setLookAndFeel(info.getClassName());
					break;
				}
			}
		} catch(UnsupportedLookAndFeelException | ClassNotFoundException | InstantiationException | IllegalAccessException e) {
			
		};
		
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				gridLayout();
			}
		});
	}
	
	private static void flowLayout() {
		JFrame f = new JFrame("Layout");
		f.setLayout(new FlowLayout());
		f.setSize(500,500);
		
		FlowLayout flowLayout = new FlowLayout();
		flowLayout.setAlignment(FlowLayout.RIGHT);
		f.setLayout(flowLayout);

		JButton leftButton = new JButton("left");
		JButton middleButton = new JButton("middle");
		JButton rightButton = new JButton("right");

		
		f.add(leftButton);
		f.add(middleButton);
		f.add(rightButton);
		f.setVisible(true);
	}
	
	private static void borderLayout() {
		JFrame f = new JFrame("Layout");
		f.setLayout(new BorderLayout());
		f.setSize(500,500);
		
		BorderLayout borderLayout = new BorderLayout(5, 5);
		f.setLayout(borderLayout);
		
		String[] names = {"um", "dois", "tres", "quatro", "cinco"};
		JButton[] buttons = new JButton[names.length];
		
		for(int i=0; i < names.length; i++) {
			buttons[i] = new JButton(names[i]);
		}
		
		f.add(buttons[0], BorderLayout.NORTH);
		f.add(buttons[1], BorderLayout.SOUTH);
		f.add(buttons[2], BorderLayout.EAST);
		f.add(buttons[3], BorderLayout.WEST);
		f.add(buttons[4], BorderLayout.CENTER);
		
		f.setVisible(true);
	}
	
	private static void gridLayout() {
		JFrame f = new JFrame("Layout");
		f.setLayout(new GridLayout());
		f.setSize(500,500);
		
		GridLayout gridLayout = new GridLayout(2, 3, 5, 5);
		f.setLayout(gridLayout);
		
		String[] names = {"um", "dois", "tres", "quatro", "cinco", "seis"};
		JButton[] buttons = new JButton[names.length];
		
		for(int i=0; i < names.length; i++) {
			buttons[i] = new JButton(names[i]);
			f.add(buttons[i]);
		}
	
		f.setVisible(true);
	}
}

