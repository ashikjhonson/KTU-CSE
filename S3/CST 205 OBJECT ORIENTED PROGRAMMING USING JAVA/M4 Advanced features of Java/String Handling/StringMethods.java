class StringMethods
{
    public static void main(String[] args) 
    {
        String s = "Ashik";
        String a = "ashik";
        System.out.println(s.toUpperCase());
        System.out.println(s.toLowerCase());
        System.out.println(s.length()); // String length
        System.out.println(a.replace("k", "q"));
        System.out.println(s.charAt(0));
        System.out.println(a.equals(s));
        System.out.println(a.equalsIgnoreCase(s));
        char ashik[] = new char[s.length()];
        ashik = s.toCharArray();
    }
}