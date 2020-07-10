class HackerEarth{
	int setValue(){
		int a = 10;
		int b = 20;
		try{
			++a;
			b++;
		}
		catch(java.io.FileNotFoundException e)
		{
			System.out.println("Error");
		}
		finally{
			a++;
			b--;
		}
		return a+b;
	}
	public static void main(String[] args)
	{
		System.out.println(new HackerEarth().setValue());
	}
}