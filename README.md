# CESE Trabajo final de Protocolos de Comunicacion en Sistemas Embebidos

## Implementacion de un driver generico basado en polling para el MPU6050

### Introduccion
Driver generico para el gyroscopio, acelerometro y termometro del MPU 6050. Se encuentra la implementacion para un µC STM32F429ZI. Permite la configuracion y lectura de los 3 parametros de forma independiente.

### Implementacion
La implementacion del driver utiliza la comunicacion bloqueante del modulo I2C del µC organizado con la siguiente estructura

```bash
MPU6050/
├── inc
│   ├── API_MPU6050.h
│   └── MPU6050_stm32F429xxZI_port.h
└── src
    ├── API_MPU6050.c
    └── MPU6050_stm32F429xxZI_port.c
```

### Ejemplo
