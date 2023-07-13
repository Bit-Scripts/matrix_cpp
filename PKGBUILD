pkgname=Matrix_CPP
pkgver=1.0.15
pkgrel=1
pkgdesc="Video processing with Matrix effect"
arch=('x86_64')
url="https://github.com/Bit-Scripts/Matrix_CPP"
license=('MIT')
depends=('linux-zen-headers' 'linux-lts-headers' 'linux-hardened-headers' 'linux-headers' 'dkms' 'qt6-base' 'qt6-multimedia' 'qt6-multimedia-ffmpeg' 'qt6-multimedia-gstreamer' 'qt6-wayland' 'opencv' 'ffmpeg' 'v4l2loopback-dkms' 'v4l2loopback-utils' 'v4l-utils')
makedepends=('cmake')
source=("v${pkgver}.tar.gz::https://github.com/Bit-Scripts/Matrix_CPP/archive/refs/tags/v${pkgver}.tar.gz")
sha256sums=('34bd309f6623aaeeb87bc6c99061a543b9b466e8fd8ff7a7d5764da01b5fcd5c')

build() {
  cd "${srcdir}/${pkgname}-${pkgver}"
  mkdir -p build
  cd build
  cmake ..
  make
}

package() {
  if [[ "$(uname -r)" == *linux-zen* ]]; then
    depends+=('linux-zen-headers')
  elif [[ "$(uname -r)" == *linux-lts* ]]; then
    depends+=('linux-lts-headers')
  elif [[ "$(uname -r)" == *linux-hardened* ]]; then
    depends+=('linux-hardened-headers')
  elif [[ "$(uname -r)" == *linux* ]]; then
    depends+=('linux-headers')
  fi
  cd "${srcdir}/${pkgname}-${pkgver}/build"
  mkdir -p "$pkgdir/usr/local/bin/matrixresources"
  mkdir -p "$pkgdir/usr/bin"
  ln -s "$pkgdir/usr/local/bin/Matrix" "$pkgdir/usr/bin/"
  ln -s "$pkgdir/usr/local/bin/matrixresources" "$pkgdir/usr/bin/"
  make DESTDIR="${pkgdir}" install
}