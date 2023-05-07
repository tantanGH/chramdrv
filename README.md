# CHRAMDRV.X

Change current drive to RAMDISK for X680x0/Human68k

最初に見つかったRAMDISKドライブにカレントドライブを移動します。

---

## Install

CHRAMDRV.ZIP をダウンロードして展開し、CHRAMDRV.X をパスの通ったディレクトリにコピーします。

---

## Usage

        CHRAMDRV.X

と単独で実行します。RAMDISKが存在すればカレントドライブをそのドライブに移します。終了コード0が返ります。なお、ドライブ上のディレクトリは移動しません。

RAMDISKが存在しなければカレントドライブは変わりません。終了コード1が返ります。
