
 PARAMETER VERSION = 2.2.0


BEGIN OS
 PARAMETER OS_NAME = standalone
 PARAMETER OS_VER = 7.0
 PARAMETER PROC_INSTANCE = microblaze_1
 PARAMETER stdin = axi_uartlite_0
 PARAMETER stdout = axi_uartlite_0
END


BEGIN PROCESSOR
 PARAMETER DRIVER_NAME = cpu
 PARAMETER DRIVER_VER = 2.9
 PARAMETER HW_INSTANCE = microblaze_1
 PARAMETER compiler_flags =  -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-mul -mxl-multiply-high -mhard-float -mxl-float-convert -mxl-float-sqrt -mno-xl-soft-div -mcpu=v11.0
END


BEGIN DRIVER
 PARAMETER DRIVER_NAME = axidma
 PARAMETER DRIVER_VER = 9.9
 PARAMETER HW_INSTANCE = axi_dma_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = llfifo
 PARAMETER DRIVER_VER = 5.3
 PARAMETER HW_INSTANCE = axi_fifo_mm_s_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = intc
 PARAMETER DRIVER_VER = 3.9
 PARAMETER HW_INSTANCE = axi_intc_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = spi
 PARAMETER DRIVER_VER = 4.4
 PARAMETER HW_INSTANCE = axi_quad_spi_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = tmrctr
 PARAMETER DRIVER_VER = 4.5
 PARAMETER HW_INSTANCE = axi_timer_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartlite
 PARAMETER DRIVER_VER = 3.2
 PARAMETER HW_INSTANCE = axi_uartlite_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = mig
 PARAMETER DRIVER_VER = 1.0
 PARAMETER HW_INSTANCE = ddr4_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = uartlite
 PARAMETER DRIVER_VER = 3.2
 PARAMETER HW_INSTANCE = mdm_0
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 4.3
 PARAMETER HW_INSTANCE = microblaze_1_local_memory_dlmb_bram_if_cntlr
END

BEGIN DRIVER
 PARAMETER DRIVER_NAME = bram
 PARAMETER DRIVER_VER = 4.3
 PARAMETER HW_INSTANCE = microblaze_1_local_memory_ilmb_bram_if_cntlr
END


