import javax.swing.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class DigitalClock extends JFrame {
    JLabel clockLabel;

    public DigitalClock() {
        clockLabel = new JLabel("", SwingConstants.CENTER);
        add(clockLabel);
        setTitle("Digital Clock");
        setSize(200, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        updateClock();
    }

    private void updateClock() {
        Timer timer = new Timer(1000, e -> {
            String currentTime = new SimpleDateFormat("HH:mm:ss").format(new Date());
            clockLabel.setText(currentTime);
        });
        timer.start();
    }

    public static void main(String[] args) {
        new DigitalClock();
    }
}
