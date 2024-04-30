import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class temp extends JFrame implements ActionListener {
    JFrame frame1 = null;
    JButton button1 = null;
    JPanel panel = null;

    public temp() {
        frame1 = new JFrame();
        frame1.setVisible(true);
        frame1.setSize(400, 200);
        frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        button1 = new JButton("Click Me !!!");
        panel = new JPanel();

        panel.add(button1);
//        button1.setSize(50,50); // useless line
        // button1.setPreferredSize(new Dimension(100,50));
        button1.addActionListener(this);
//        frame1.add(button1, BorderLayout.CENTER);
        // frame1.setLayout(new BorderLayout(20,20));

        // Container contentPane = frame1.getContentPane(); // ?????
        // contentPane.add(button1, BorderLayout.CENTER);

        frame1.getContentPane().add(panel);
    }


    public static void main(String[] args) {
        new temp();
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        if (actionEvent.getSource() == button1) {
            JOptionPane.showMessageDialog(null, "Thank You");
        }
    }
}
