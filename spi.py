import spidev

# Open SPI bus 0, device (Chip Select) 0
spi = spidev.SpiDev()
spi.open(0, 0)

# Set clock speed and mode
spi.max_speed_hz = 500000
spi.mode = 0

# Send command array and receive response
data_tx = [0x01, 0x80, 0x00]
data_rx = spi.xfer2(data_tx)

print("Received:", data_rx)
spi.close()
