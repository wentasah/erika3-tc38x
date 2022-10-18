with import <nixpkgs> {};
pkgsCross.mingwW64.stdenv.mkDerivation {
  name = "cygpath-dummy";
  src = ./.;
  installPhase = ''
    install -D -t $out/bin cygpath.exe
  '';
}
