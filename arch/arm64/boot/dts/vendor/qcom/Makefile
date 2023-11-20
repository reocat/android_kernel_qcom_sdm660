ifeq ($(CONFIG_BUILD_ARM64_DT_OVERLAY),y)
        dtbo-$(CONFIG_ARCH_SDM660) += \
                sdm660-mtp-external-codec-overlay.dtbo \
                sdm660-mtp-internal-codec-overlay.dtbo \
                sdm660-cdp-external-codec-overlay.dtbo \
                sdm660-cdp-internal-codec-overlay.dtbo \
                sdm660-qrd-external-codec-overlay.dtbo \
                sdm660-rcm-external-codec-overlay.dtbo \
                sdm660-rcm-internal-codec-overlay.dtbo \
                sda660-mtp-external-codec-overlay.dtbo \
                sda660-cdp-external-codec-overlay.dtbo \
                sda660-rcm-external-codec-overlay.dtbo

sdm660-mtp-external-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-mtp-internal-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-cdp-external-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-cdp-internal-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-qrd-external-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-rcm-external-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sdm660-rcm-internal-codec-overlay.dtbo-base := sdm660-pm660l.dtb

sda660-mtp-external-codec-overlay.dtbo-base := sda660-pm660l.dtb

sda660-cdp-external-codec-overlay.dtbo-base := sda660-pm660l.dtb

sda660-rcm-external-codec-overlay.dtbo-base := sda660-pm660l.dtb
else
dtb-$(CONFIG_ARCH_SDM660) += sdm660-mtp.dtb \
        sdm630-mtp.dtb \
	sdm660-qrd.dtb \
	sdm660-cdp-c1n-preEVT.dtb \
	sdm660-cdp-c1n-EVT.dtb \
	sdm660-mtp-c1n-preEVT.dtb \
	sdm660-mtp-c1n-EVT.dtb \
	sdm660-mtp-c1n-EVT2.0.dtb \
	sdm660-mtp-c1n-EVT2.1.dtb \
	sdm660-mtp-pl2-preEVT.dtb \
	sdm630-cdp-c1n-preEVT.dtb \
	sdm630-cdp-c1n-EVT.dtb \
	sdm630-mtp-c1n-preEVT.dtb \
        sdm630-mtp-c1n-EVT.dtb \
	sdm630-mtp-c1n-EVT2.0.dtb \
	sdm630-mtp-c1n-EVT2.1.dtb \
	sdm630-mtp-pl2-preEVT.dtb \
	sdm630-mtp-pl2-EVT1.5.dtb \
	sdm630-mtp-pl2-EVT1.5-CD.dtb \
	sdm630-mtp-pl2-dvt.dtb \
	sdm660-mtp-b2n-preEVT.dtb \
	sdm660-mtp-b2n-EVT.dtb \
	sdm660-mtp-b2n-EVT1.5.dtb \
	sdm660-mtp-b2n-DVT-QC.dtb \
	sdm660-mtp-b2n-DVT-TI.dtb \
	sdm636-mtp-drg-preEVT.dtb \
	sdm636-mtp-b2n-preEVT.dtb \
	sdm636-mtp-ctl-EVT.dtb \
        sdm636-mtp-drg-EVT.dtb \
	sdm636-mtp-ctl-DVT.dtb \
        sdm636-mtp-drg-DVT1.5.dtb \
        sdm660-mtp-drg-pro-EVT.dtb \
        sdm636-mtp-hc1-preEVT.dtb \
        sdm660-mtp-tas-preEVT.dtb \
        sdm660-mtp-tas-EVT.dtb \
        sdm660-mtp-tas-PVT.dtb \
        sdm660-mtp-tas-MP.dtb \
#dtb-$(CONFIG_ARCH_SDM660) += sdm660-sim.dtb \
#	sdm660-internal-codec-cdp.dtb \
#	sdm660-internal-codec-mtp.dtb \
#	sdm660-internal-codec-rcm.dtb \
#	sdm660-cdp.dtb \
#	sdm660-mtp.dtb \
#	sdm660-qrd.dtb \
#	sdm660-rcm.dtb \
#	sdm660-rumi.dtb \
#	sdm660-pm660a-cdp.dtb \
#	sdm660-pm660a-mtp.dtb \
#	sdm660-pm660a-qrd.dtb \
#	sdm660-pm660a-rcm.dtb \
#	sdm660-pm660a-rumi.dtb \
#	sdm660-internal-codec-pm660a-cdp.dtb \
#	sdm660-internal-codec-pm660a-mtp.dtb \
#	sdm660-internal-codec-pm660a-rcm.dtb \
#	sdm660-pm660a-sim.dtb \
#	sda660-cdp.dtb \
#	sda660-mtp.dtb \
#	sda660-rcm.dtb \
#	sda660-pm660a-cdp.dtb \
#	sda660-pm660a-mtp.dtb \
#	sda660-pm660a-rcm.dtb \
#	sda660-pm660a-qrd-hdk.dtb \
#	sdm660-headset-jacktype-no-cdp.dtb \
#	sdm660-headset-jacktype-no-rcm.dtb \
#	sdm660-pm660a-headset-jacktype-no-cdp.dtb \
#	sdm660-pm660a-headset-jacktype-no-rcm.dtb \
#	sdm660-usbc-audio-mtp.dtb \
#	sdm660-usbc-audio-rcm.dtb \
#	sdm658-mtp.dtb \
#	sdm658-cdp.dtb \
#	sdm658-rcm.dtb \
#	sdm658-qrd.dtb \
#	sdm658-pm660a-mtp.dtb \
#	sdm658-pm660a-cdp.dtb \
#	sdm658-pm660a-rcm.dtb \
#	sdm658-pm660a-qrd.dtb \
#	sdm658-internal-codec-mtp.dtb \
#	sdm658-internal-codec-cdp.dtb \
#	sdm658-internal-codec-rcm.dtb \
#	sdm658-internal-codec-pm660a-mtp.dtb \
#	sdm658-internal-codec-pm660a-cdp.dtb \
#	sdm658-internal-codec-pm660a-rcm.dtb \
#	sda658-cdp.dtb \
#	sda658-mtp.dtb \
#	sda658-rcm.dtb \
#	sda658-pm660a-mtp.dtb \
#	sda658-pm660a-cdp.dtb \
#	sda658-pm660a-rcm.dtb \
#	sdm636-cdp.dtb \
#	sdm636-mtp.dtb \
#	sdm636-qrd.dtb \
#	sdm636-rcm.dtb \
#	sdm636-headset-jacktype-no-cdp.dtb \
#	sdm636-headset-jacktype-no-rcm.dtb \
#	sdm636-internal-codec-cdp.dtb \
#	sdm636-internal-codec-mtp.dtb \
#	sdm636-internal-codec-pm660a-cdp.dtb \
#	sdm636-internal-codec-pm660a-mtp.dtb \
#	sdm636-internal-codec-pm660a-rcm.dtb \
#	sdm636-internal-codec-rcm.dtb \
#	sdm636-pm660a-headset-jacktype-no-cdp.dtb \
#	sdm636-pm660a-headset-jacktype-no-rcm.dtb \
#	sdm636-pm660a-cdp.dtb \
#	sdm636-pm660a-mtp.dtb \
#	sdm636-pm660a-qrd.dtb \
#	sdm636-pm660a-rcm.dtb \
#	sdm636-usbc-audio-mtp.dtb \
#	sdm636-usbc-audio-rcm.dtb \
#	sda636-cdp.dtb \
#	sda636-mtp.dtb \
#	sda636-rcm.dtb \
#	sda636-pm660a-cdp.dtb \
#	sda636-pm660a-mtp.dtb \
#	sda636-pm660a-qrd-hdk.dtb \
#	sda636-pm660a-rcm.dtb

#dtb-$(CONFIG_ARCH_SDM630) += sdm630-rumi.dtb \
#	sdm630-pm660a-rumi.dtb \
#	sdm630-mtp.dtb \
#	sdm630-usbc-audio-mtp.dtb \
#	sdm630-usbc-audio-rcm.dtb \
#	sdm630-cdp.dtb \
#	sdm630-rcm.dtb \
#	sdm630-internal-codec-mtp.dtb \
#	sdm630-internal-codec-cdp.dtb \
#	sdm630-internal-codec-rcm.dtb \
#	sdm630-pm660a-cdp.dtb \
#	sdm630-pm660a-mtp.dtb \
#	sdm630-pm660a-rcm.dtb \
#	sdm630-pm660a-qrd.dtb \
#	sdm630-internal-codec-pm660a-cdp.dtb \
#	sdm630-internal-codec-pm660a-mtp.dtb \
#	sdm630-internal-codec-pm660a-rcm.dtb \
#	sda630-mtp.dtb \
#	sda630-cdp.dtb \
#	sda630-rcm.dtb \
#	sda630-pm660a-mtp.dtb \
#	sda630-pm660a-cdp.dtb \
#	sda630-pm660a-rcm.dtb \
#	sda630-pm660a-qrd-hdk.dtb \
#	sdm630-headset-jacktype-no-cdp.dtb \
#	sdm630-headset-jacktype-no-rcm.dtb \
#	sdm630-pm660a-headset-jacktype-no-cdp.dtb \
#	sdm630-pm660a-headset-jacktype-no-rcm.dtb \
#	sdm455-mtp.dtb \
#	sdm455-qrd.dtb \
#	sdm455-cdp.dtb
endif

always		:= $(dtb-y)
subdir-y	:= $(dts-dirs)
clean-files    := *.dtb *.dtbo
