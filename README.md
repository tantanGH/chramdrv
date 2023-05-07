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

注意：純正`RAMDISK.SYS`と`060turbo.sys`のRAMDISKでのみ動作確認しています。特殊なIDを返すRAMDISKドライバの場合は正常に判定できないかもしれません。

---

## 何に使うのか？

基本的には X68000Z で起動用XDFからブートし、RAMDISKにファイルを展開するケースを想定しています。
X68000Z EAK 1.1.3 の状況では HDDイメージに対応していないので、RAMDISKを作成すると A: B:がFD, C:がRAMDISKとなりますが、まもなく対応がなされるHDDイメージを使うとドライブC:からはHDDが使うことになります。RAMDISKはその後のドライブレターが割り振られるため環境によって違いが出てきます。

このプログラムを使うことで、環境によらずに最初のRAMDISKドライブを見つけてそこにカレントドライブを移すことができるので、そこにファイルを展開すれば良いことになります。


`CONFIG.SYS`内で純正`RAMDISK.SYS`を使って4MBのRAMDISKを定義する例:

        DEVICE = \SYS\RAMDISK.SYS #M4096

`AUTOEXEC.BAT`内でRAMDISKドライブにカレントドライブを移し、そこでFDから圧縮ファイルを展開する例:

        CHRAMDRV.X
        if NOT EXITCODE 0 GOTO ERROR

        cd \
        lx -c A:\hogehoge.lzh
        GOTO END

        :ERROR
        echo RAMDISK is not available.

        :END
---