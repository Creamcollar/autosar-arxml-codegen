# AUTOSAR DIO Driver Files

Generated on: 2026-05-23 15:19:58
Source ARXML: dio_config.arxml

## Files Generated:

- Dio_Cfg.h: DIO Configuration Header
- Dio.h: DIO Driver Header
- Dio.c: DIO Driver Implementation

## Configuration Summary:

### Ports: 1
- DioPort (ID: 0)

### Channels: 1
- DioChannel (ID: 0, Port: 0)

### Channel Groups: 1
- DIO_GROUP_0 (Port: 0, Mask: 0x00FF, Offset: 0)

## API Features:
- DEV_ERROR_DETECT: ENABLED if self.config_data['dev_error_detect'] else DISABLED
- VERSION_INFO_API: ENABLED if self.config_data['version_info_api'] else DISABLED
- FLIP_CHANNEL_API: ENABLED if self.config_data['flip_channel_api'] else DISABLED
- MASKED_WRITE_PORT_API: ENABLED if self.config_data['masked_write_port_api'] else DISABLED
