<?hh

<<__EntryPoint>>
function main() {
  $a = __hhvm_intrinsics\launder_value(vec[]);
  $a[] = "hello";
  var_dump(json_encode($a));
  var_dump(serialize($a));
  var_dump(fb_serialize($a, FB_SERIALIZE_HACK_ARRAYS));
}